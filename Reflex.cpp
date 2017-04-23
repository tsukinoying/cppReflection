#include <map>
#include "Reflex.h"
//Reflex.cpp
static std::map< string, ClassInfo*> *classInfoMap = NULL;
bool Object::Register(ClassInfo* ci)
{
    if (!classInfoMap)  {
        classInfoMap = new std::map< string, ClassInfo*>();   //这里我们是通过map来存储这个映射的。
    }
    if (ci) {
        if (classInfoMap->find(ci->m_className) == classInfoMap->end()){
            classInfoMap->insert(std::map< string, ClassInfo*>::value_type(ci->m_className, ci)); // 类名 <-> classInfo
        }
    }
    return true;
}
Object* Object::CreateObject(std::string name)
{
    std::map< string, ClassInfo*>::const_iterator iter = classInfoMap->find(name);
    if (classInfoMap->end() != iter) {
        return iter->second->CreateObject();     //当传入字符串name后,通过name找到info,然后调用对应的CreatObject()即可
    }
    return NULL;
}