//#include"H_obj_c11.h"
//#include "H_obj_verj_op.h"
#include"H_obj_verj_op.h"

class triel{
 int a;
 int b; 
 triel(const triel&);
public: 
  triel(int aa,int bb):a(aa),b(bb){};
void stugelu(){
std::cout<<" a="<<a<<" b="<<b<<std::endl;
}
 friend std::ostream& operator<<(std::ostream& out, triel& t);
};

std::ostream& operator<<(std::ostream& out,triel& t){
  out<<t.a<<" "<<t.b<<"\n";
  return out;
}


int main(){ 
	obj_pool<int,6> obj;
	
	int* a = obj.NewObject();
	*a = 15;
        int*b=obj.NewObject(12);
        const int* c=obj.NewObject(24);
        const int* cc=c;
        int  *d=obj.NewObject(19);
        obj.Reset(cc);
        obj.Reset(c);
        int *f=obj.NewObject();
         *f=13;
 	std::cout<<"OBJECTS OF POOL <<obj>>\n"<<obj;
	std::cout<<*a<<" "<<*b<<" "<<*c<<" "<<" "<<*d<<" "<<*f<<"\n"<<std::endl;
         std::cout<<a<<" "<<b<<" "<<c<<" "<<" "<<d<<" "<<f<<"\n"<<std::endl;
        std::cout<<*a<<" "<<*b<<" "<<*c<<" "<<" "<<*d<<" "<<*f<<"\n"<<std::endl;
         
         obj_pool<triel,2> obj_tr;
        triel* tr_obj1=obj_tr.NewObject(2,3);
	triel* tr_obj2=obj_tr.NewObject(5,8);
            (*tr_obj1).stugelu();
	std::cout<<"Obj-i parunakutyun@`"<<obj_tr;
     	std::cout<<"Taroxutyun="<<obj.max_count()<<" obj_count="<<obj.obj_count()<<" karox enq der avelacnel "<<obj.receptivity()<<" obyekt"<<std::endl;
      std::cout<<"Type is "<<obj.type()<<"\n";   
 
         
obj_pool<int,9> objint;
 	int* ff=objint.NewObject(32);
        objint+=obj;
    std::cout<<"objcount? "<<objint.obj_count()<<"\n";	
obj.evacuate();
std::cout<<"Pool after evacuation\n";
 std::cout<<obj;
        std::cout<<"Is empty? "<<obj.is_empty()<<"\n";
std::cout<<"Type` "<<obj.type()<<std::endl;

        obj_pool<triel,5> objj;
std::cout<<"Type of pool` <<objj>> "<<objj.type()<<std::endl;

      return 0;
}





