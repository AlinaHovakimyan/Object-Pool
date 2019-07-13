#ifndef H_obj_pop
#define H_obj_pop

#include<iostream>
#include<typeinfo>
#include<new>

class exceptions{};
class count_error:public exceptions{};
class pool_is_full:public exceptions{};
class invalid_reset_address:public exceptions{};

template<typename T=int, unsigned count=32>
class obj_pool{  
   
   T* memory_p_begin;
   bool* memory_flags;
   int pool_size;
   int object_count;
   void ObjFunc();
public:
        obj_pool();
	template<typename T_arg1> obj_pool(T_arg1);
        template<typename T_arg1,typename T_arg2>  obj_pool(T_arg1, T_arg2);
        template<typename T_arg1,typename T_arg2,typename T_arg3>  obj_pool(T_arg1, T_arg2,T_arg3);
	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4>  obj_pool(T_arg1, T_arg2,T_arg3,T_arg4);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5>  obj_pool(T_arg1, 				  T_arg2,T_arg3,T_arg4,T_arg5);
	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6>  obj_pool(T_arg1,   T_arg2,T_arg3,T_arg4,T_arg5,T_arg6);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7>  obj_pool(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7,typename T_arg8>  obj_pool(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7,T_arg8);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7,typename T_arg8,typename T_arg9>  obj_pool(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7,T_arg8,T_arg9);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7,typename T_arg8,typename T_arg9,typename T_arg10>  obj_pool(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7,T_arg8,T_arg9,T_arg10);	
	T* NewObject();
	void Reset(const T* const );
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
void obj_pool<T,count>::ObjFunc(){
		

	pool_size = sizeof(T)*count;
	memory_p_begin=reinterpret_cast<T*>(operator new(pool_size));
	object_count=0;
	memory_flags= new  bool[count];

}

template<typename T, unsigned count>
obj_pool<T,count>::obj_pool(){
		ObjFunc();
        for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T();
  		*(memory_flags+i)=0;
  		}
             
        
}


template<typename T,unsigned count>
template<typename T_arg1> obj_pool<T,count>::obj_pool(T_arg1 arg1){
		
		ObjFunc();
  	for(int i=0;i<count;i++){
	 new (memory_p_begin+i) T(arg1);
  	 *(memory_flags+i)=0;
  	}
}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2>  obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2);
  		*(memory_flags+i)=0;
	}
}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3> obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3){
		
	ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3);
  	  *(memory_flags+i)=0;
	}
}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4>  obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3,arg4);
  		*(memory_flags+i)=0;
	}
}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5>  obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3,arg4,arg5);
  		*(memory_flags+i)=0;
	}

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6>  obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3,arg4,arg5,arg6);
  		*(memory_flags+i)=0;
	}

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7>  obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3,arg4,arg5,arg6,arg7);
  		*(memory_flags+i)=0;
	}

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7, typename T_arg8>  obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7, T_arg8 arg8){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8);
  		*(memory_flags+i)=0;
	}

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7, typename T_arg8, typename T_arg9>  obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7, T_arg8 arg8, T_arg9 arg9){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9);
  		*(memory_flags+i)=0;
	}

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7, typename T_arg8, typename T_arg9, typename T_arg10> obj_pool<T,count>::obj_pool(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7, T_arg8 arg8, T_arg9 arg9, T_arg10 arg10){
		ObjFunc();
  	for(int i=0;i<count;i++){
	   new (memory_p_begin+i) T(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10);
  		*(memory_flags+i)=0;
	}

}


template<typename T,unsigned count>
T* obj_pool<T,count>::NewObject(){
		  int i=0;
	while( (*(memory_flags+i)==1) && (i<count) ){

		i++;
	 }
       if(i==count) throw pool_is_full();
		*(memory_flags+i)=1;
		 object_count++;
    return memory_p_begin+i;
}

template <typename T,unsigned count>
 void obj_pool<T,count>::Reset(const T* const reset_p){
 
	   if((reset_p < memory_p_begin) || ( reset_p > memory_p_begin+count)) throw invalid_reset_address();
		
		if(*(memory_flags+(reset_p-reinterpret_cast<T*>(memory_p_begin)))==1){
		object_count--;
        	*(memory_flags+(reset_p-reinterpret_cast<T*>(memory_p_begin)))=0;
		};
           
}

template<typename T, unsigned count>
obj_pool<T,count>::~obj_pool(){

  	for(int i=0;i<count;i++){
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
