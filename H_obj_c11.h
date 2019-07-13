#ifndef H_obj_c11
#define H_obj_c11

#include<iostream>
#include<typeinfo>
#include<new>

class exceptions{};
class pool_is_full:public exceptions{};
class invalid_reset_address:public exceptions{};


template<typename T=int, unsigned count=32>
class obj_pool{  
   
   T* memory_p_begin;
   bool* memory_flags;
   int pool_size;
   int object_count;
   int NewObjFunc();

public:
        obj_pool();
        template<typename ...Params> T* NewObject(Params... params);
        void Reset(const T*); 
        unsigned size() const; 
        unsigned max_count() const;
        unsigned obj_count() const;
        unsigned receptivity() const;
        bool is_empty() const;	
        const char* type() const;        
	void evacuate();
	template<typename T1, unsigned count1> 
   		friend std::ostream& operator<<(std::ostream&, const obj_pool<T1,count1>&);
	~obj_pool();

};

template<typename T, unsigned count>
obj_pool<T,count>::obj_pool(){

        pool_size = sizeof(T)*count;
	memory_p_begin=reinterpret_cast<T*>(operator new(pool_size));
	object_count=0;
	memory_flags= new  bool[count];
  	for(int i=0;i<count;i++){
  		*(memory_flags+i)=0;
  		}
        
}

template<typename T,unsigned count>
template <typename... Params>T* obj_pool<T,count>::NewObject(Params... params){
	
         int i=0;
	while( (*(memory_flags+i)==1) && (i<count) ){

		i++;
	 }
       if(i==count) throw pool_is_full();
		*(memory_flags+i)=1;
		object_count++;
		T* ptr=memory_p_begin+i;
	  	new (ptr) T(params...);   
		return ptr;

}


template <typename T,unsigned count>
 void obj_pool<T,count>::Reset(const T* reset_p){
 
	    if((reset_p < memory_p_begin) || ( reset_p > memory_p_begin+sizeof(T)*count)) throw invalid_reset_address();
		
		if(*(memory_flags+(reset_p-reinterpret_cast<T*>(memory_p_begin)))==1){
		object_count--;
        	*(memory_flags+(reset_p-reinterpret_cast<T*>(memory_p_begin)))=0;
		(*reset_p).~T();
		};
           
}

template<typename T, unsigned count>
obj_pool<T,count>::~obj_pool(){
	for(int i=0;i<count;i++){
  		if(*(memory_flags+i)==1)
		(*(memory_p_begin+i)).~T();
  	}
	operator delete (memory_p_begin);
	delete[] memory_flags;
}

template<typename T,unsigned count>
unsigned obj_pool<T,count>::size() const {
	
	return pool_size;
}

template<typename T,unsigned count>
unsigned obj_pool<T,count>::max_count() const {
	
	return count;
}

template<typename T,unsigned count>
unsigned obj_pool<T,count>::obj_count() const {
   
	return object_count;
}

template<typename T,unsigned count>
unsigned obj_pool<T,count>::receptivity() const {
	
	return count-object_count;
}

template<typename T,unsigned count>
bool obj_pool<T,count>::is_empty() const {
	
	return (object_count==0)? true : false; 
}

template<typename T,unsigned count>
void obj_pool<T,count>::evacuate(){
	
if(object_count!=0){
		for(int i=0;i<count;i++){
		   if(*(memory_flags+i)==1){
		   (*(memory_p_begin+(i+1))).~T();
     		   *(memory_flags+i)=0;
		   }
		};		
        object_count=0;
	};

}

template<typename T,unsigned count>
const char* obj_pool<T,count>::type() const{
	return typeid(T).name();

}

template<typename T1, unsigned count1>
 std::ostream& operator<<(std::ostream& out,const obj_pool<T1,count1>& obj){
	if(obj.is_empty()) 
		out<<"Pool is empty";
  	else {
		for(int i=0;i<count1;i++){
			if(*(obj.memory_flags+i)==1)
			out<<*(obj.memory_p_begin+i)<<" ";
    
		}
       }	
    out<<std::endl;
	return out;
}


#endif







