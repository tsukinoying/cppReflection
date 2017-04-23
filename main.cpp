#include <iostream>
#include "Reflex.h"

class B : public Object
{
public:
    B(){ cout << hex << (long)this << " B constructor!" << endl; }
    ~B(){ cout << hex << (long)this << " B destructor!" << endl; }
    virtual ClassInfo* GetClassInfo() const{ return &ms_classinfo; }
    static Object* CreateObject() { return new B; }
protected:
    static ClassInfo ms_classinfo;
};
ClassInfo B::ms_classinfo("B", B::CreateObject);
class C : public Object
{

    virtual ClassInfo* GetClassInfo() const{ return &ms_classinfo; }
    static Object* CreateObject() { return new C; }
protected:
    static ClassInfo ms_classinfo;

public:
    C(){
        cout<<"ok"<<endl;
    }

};
ClassInfo C::ms_classinfo("C", C::CreateObject);
int main()
{
    Object* obj = Object::CreateObject("C");
    delete obj;
    return 0;
}