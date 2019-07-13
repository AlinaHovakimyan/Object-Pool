#ifndef H_obj_verj_qn
#define H_obj_verj_qn

#include<iostream>
#include<typeinfo>
#include<new>

class exceptions{};
class pool_is_full:public exceptions{};
class invalid_reset_address:public exceptions{};
class added_bigger_pool:public exceptions{};


template<typename T=int, unsigned count=32>
class obj_pool{  
   
   T* memory_p_begin;
   bool* memory_flags;
   int pool_size;
   int object_count;
   int NewObjFunc();
public:
        obj_pool();
        T* NewObject();
        template<typename T_arg1> T* NewObject(T_arg1);
        template<typename T_arg1,typename T_arg2> T* NewObject(T_arg1, T_arg2);
        template<typename T_arg1,typename T_arg2,typename T_arg3> T* NewObject(T_arg1, T_arg2,T_arg3);
	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4> T* NewObject(T_arg1, T_arg2,T_arg3,T_arg4);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5> T* NewObject(T_arg1, 				  T_arg2,T_arg3,T_arg4,T_arg5);
	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6> T* NewObject(T_arg1,   T_arg2,T_arg3,T_arg4,T_arg5,T_arg6);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7> T* NewObject(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7,typename T_arg8> T* NewObject(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7,T_arg8);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7,typename T_arg8,typename T_arg9> T* NewObject(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7,T_arg8,T_arg9);

	template<typename T_arg1,typename T_arg2,typename T_arg3,typename T_arg4,typename T_arg5,typename T_arg6,typename T_arg7,typename T_arg8,typename T_arg9,typename T_arg10> T* NewObject(T_arg1, T_arg2,T_arg3,T_arg4,T_arg5,T_arg6,T_arg7,T_arg8,T_arg9,T_arg10);	

	void Reset(const T* const );
        unsigned size() const; 
        unsigned max_count() const;
        unsigned obj_count() const;
        unsigned receptivity() const;
        bool is_empty() const;	
        const char* type() const;       
	void evacuate();
	 T* get_memory_begin() const;
	 bool* get_memory_flags() const;
	
	template<typename T1, unsigned count1> 
   		friend std::ostream& operator<<(std::ostream&, const obj_pool<T1,count1>&);
	template<unsigned count2>
		obj_pool<T,count>& operator=(const obj_pool<T,count2>);
	template<typename T1,unsigned count1,unsigned count2> 
		friend obj_pool<T1,count1>& operator+=(obj_pool<T1,count1>&,const obj_pool<T1,count2>&);
        template<typename T1,unsigned count1,unsigned count2> 
		friend obj_pool<T1,count1+count2> operator+(const obj_pool<T1,count1>&,const obj_pool<T1,count2>&);
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


template<typename T, unsigned count>
int obj_pool<T,count>::NewObjFunc(){
        int i=0;
	while( (*(memory_flags+i)==1) && (i<count) ){

		i++;
	 }
       if(i==count) throw pool_is_full();
		*(memory_flags+i)=1;
		object_count++;
		return i;
}

template<typename T,unsigned count>
T* obj_pool<T,count>::NewObject(){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
	  	new (ptr) T();   
		return ptr;
}

template<typename T,unsigned count>
template<typename T_arg1> T* obj_pool<T,count>::NewObject(T_arg1 arg1){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
		new (ptr) T(arg1);
		return ptr;
}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		 new (ptr) T(arg1,arg2);
		return ptr;
}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		 new (ptr) T(arg1,arg2,arg3);
		return  ptr;

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		 new (ptr) T(arg1,arg2,arg3,arg4);
		return ptr;
}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		new (ptr) T(arg1,arg2,arg3,arg4,arg5);
		return ptr;

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		new (ptr) T(arg1,arg2,arg3,arg4,arg5, arg6);
		return ptr;

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		 new (ptr) T(arg1,arg2,arg3,arg4,arg5, arg6, arg7);
		return ptr;

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7, typename T_arg8> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7, T_arg8 arg8){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		new (ptr) T(arg1,arg2,arg3,arg4,arg5, arg6, arg7,arg8);
		return ptr;

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7, typename T_arg8, typename T_arg9> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7, T_arg8 arg8, T_arg9 arg9){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		 new (ptr) T(arg1,arg2,arg3,arg4,arg5, arg6, arg7,arg8, arg9);
		return ptr;

}

template<typename T,unsigned count>
template<typename T_arg1, typename T_arg2, typename T_arg3, typename T_arg4, typename T_arg5, typename T_arg6, typename T_arg7, typename T_arg8, typename T_arg9, typename T_arg10> T* obj_pool<T,count>::NewObject(T_arg1 arg1,T_arg2 arg2, T_arg3 arg3, T_arg4 arg4, T_arg5 arg5, T_arg6 arg6, T_arg7 arg7, T_arg8 arg8, T_arg9 arg9, T_arg10 arg10){
		int i=NewObjFunc();
		T* ptr=memory_p_begin+i;
 		new (ptr) T(arg1,arg2,arg3,arg4,arg5, arg6, arg7,arg8, arg9, arg10);
		return ptr;

}

template <typename T,unsigned count>
 void obj_pool<T,count>::Reset(const T* const reset_p){
 
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

 template<typename T, unsigned count>
T* obj_pool<T,count>::get_memory_begin() const{
   return memory_p_begin;
}

template<typename T, unsigned count>
bool* obj_pool<T,count>::get_memory_flags() const {
   return memory_flags;
}

template<typename T, unsigned count>
 template<unsigned count2>
obj_pool<T,count>& obj_pool<T,count>::operator=(const obj_pool<T,count2> second_pool){
	std::cout<<"my memory_p_begin "<<memory_p_begin<<std::endl;
	if (second_pool.obj_count() > count) throw added_bigger_pool(); 

	int i=0;
         const T* memory_p_2 = second_pool.get_memory_begin();
	 const bool* memory_flags_2=second_pool.get_memory_flags();

	std::cout<<"memory_p_begin of temp "<<memory_p_2<<std::endl;
         this->evacuate(); 
	while(i < count2 ){
	if(*(memory_flags_2+i)==1){
	(*(memory_p_begin+i))=(*(memory_p_2+i));
	*(memory_flags+i)=1;
	}
	i++;
	}
	object_count=second_pool.obj_count();
	return *this;
 
}

template<typename T1, unsigned count1,unsigned count2>
obj_pool<T1,count1>& operator+=(obj_pool<T1,count1>& first_pool, const obj_pool<T1,count2>& second_pool){
	
	if (second_pool.object_count > (first_pool.receptivity())) throw added_bigger_pool();
	int j=0;	
	for(int i=0;i<count1;i++){
 	 if(*(first_pool.memory_flags+i)==0){
	bool bools=false;
           while((j<count2)&&(bools==false)){
		if(*(second_pool.memory_flags+j)==1){
		(*(first_pool.memory_p_begin+i))=(*(second_pool.memory_p_begin+j));
		*(first_pool.memory_flags+i)=1;
		(first_pool.object_count)++;
		 bools=true;
		 }
		 j++;		
	   }
	}
	}
	return first_pool;
 
}

template<typename T1, unsigned count1,unsigned count2>
obj_pool<T1,count1+count2> operator+(const obj_pool<T1,count1>& first_pool, const obj_pool<T1,count2>& second_pool){
	
	obj_pool<T1,count1+count2> temp_pool;
	int j=0;	
	for(int i=0;i<count1;i++){
 	 if(*(first_pool.memory_flags+i)==1){
	bool bools=false;
           while(bools==false){
		if(*(temp_pool.memory_flags+j)==0){
		(*(temp_pool.memory_p_begin+i))=(*(first_pool.memory_p_begin+j));
		(*(temp_pool.memory_flags+i))=1;
		(temp_pool.object_count)++;
		 bools=true;
		 }
		 j++;		
	   }
	}
	}
	j=0;	
	for(int i=0;i<count2;i++){
 	 if(*(second_pool.memory_flags+i)==1){
	bool bools=false;
           while(bools==false){
		if(*(temp_pool.memory_flags+j)==0){
		(*(temp_pool.memory_p_begin+i))=(*(second_pool.memory_p_begin+j));
		(*(temp_pool.memory_flags+i))=1;
		(temp_pool.object_count)++;
		 bools=true;
		 }
		 j++;		
	   }
	}
	}
	return temp_pool;
 
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
