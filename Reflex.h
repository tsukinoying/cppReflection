//
// Created by 常英儒 on 2017/4/23.
//

#ifndef FUN_REFLEX_H
#define FUN_REFLEX_H

#include <string>

using namespace std;
class ClassInfo;

//Reflex.h
class Object
{
public:
    Object(){}
    virtual ~Object(){}
    static bool Register(ClassInfo* ci);     //注册传入一个classInfo(类信息),将这个类的信息注册到映射中
    static Object* CreateObject(string name);   //工厂生产对象的接口
};

typedef Object* (*ObjectConstructorFn)(void);

class ClassInfo
{
public:
    ClassInfo(const std::string className, ObjectConstructorFn ctor)
            :m_className(className), m_objectConstructor(ctor)
    {
        Object::Register(this);       //classInfo的构造函数是传入类名和类对应的new函数然后自动注册进map中。
    }
    virtual ~ClassInfo(){}
    Object* CreateObject()const { return m_objectConstructor ? (*m_objectConstructor)() : 0; }
    bool IsDynamic()const { return NULL != m_objectConstructor; }
    const std::string GetClassName()const { return m_className; }
    ObjectConstructorFn GetConstructor()const{ return m_objectConstructor; }
public:
    string m_className;
    ObjectConstructorFn m_objectConstructor;
};
#endif //FUN_REFLEX_H
