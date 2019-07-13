#include"H_obj_pop.h"

class triel{
 int a;
 int b; 
 triel(const triel&);
public: 
  triel(int aa):a(aa),b(12){};
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
        int*b=obj.NewObject();
	 *b=13;
        int* c=obj.NewObject();
	*c=24;
        const int* cc=c;
        int  *d=obj.NewObject();
	  *d=132;
        obj.Reset(cc);
        obj.Reset(c);
        int *f=obj.NewObject();
         *f=36;
 	std::cout<<obj;
	std::cout<<*a<<" "<<*b<<" "<<*c<<" "<<" "<<*d<<" "<<*f<<"\n"<<std::endl;
         std::cout<<a<<" "<<b<<" "<<c<<" "<<" "<<d<<" "<<f<<"\n"<<std::endl;
        std::cout<<*a<<" "<<*b<<" "<<*c<<" "<<" "<<*d<<" "<<*f<<"\n"<<std::endl;
         
         obj_pool<triel,2> obj_tr(2);
        triel* tr_obj1=obj_tr.NewObject();
	triel* tr_obj2=obj_tr.NewObject();
            (*tr_obj1).stugelu();
	std::cout<<"obj-i parunakutyun@`"<<obj_tr;
     	std::cout<<"taroxutyun="<<obj.max_count()<<" obj_count="<<obj.obj_count()<<" karox enq der avelacnel "<<obj.receptivity()<<" obyekt"<<std::endl;
      std::cout<<"Type is "<<obj.type()<<"\n";   
 
         
obj_pool<int,5> objint;
 	int* ff=objint.NewObject();
	*ff=32;
        std::cout<<"objcount? "<<objint.obj_count()<<"\n";	
obj.evacuate();
std::cout<<"heto\n";
 std::cout<<obj;
        std::cout<<"is empty? "<<obj.is_empty()<<"\n";
std::cout<<"type` "<<obj.type()<<std::endl;

        obj_pool<triel,5> objj(3);
std::cout<<"type` "<<objj.type()<<std::endl;

      return 0;
}
