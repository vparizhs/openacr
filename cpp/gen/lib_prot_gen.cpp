//
// cpp/gen/lib_prot_gen.cpp
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#include "include/algo.h"  // hard-coded include
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
//#pragma endinclude
namespace lib_prot {
    static void          SizeCheck();
} // end namespace lib_prot

// --- lib_prot.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* lib_prot::value_ToCstr(const lib_prot::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case lib_prot_FieldId_value        : ret = "value";  break;
    }
    return ret;
}

// --- lib_prot.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void lib_prot::value_Print(const lib_prot::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- lib_prot.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool lib_prot::value_SetStrptrMaybe(lib_prot::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,lib_prot_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- lib_prot.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void lib_prot::value_SetStrptr(lib_prot::FieldId& parent, algo::strptr rhs, lib_prot_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- lib_prot.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool lib_prot::value_ReadStrptrMaybe(lib_prot::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- lib_prot.FieldId..ReadStrptrMaybe
// Read fields of lib_prot::FieldId from an ascii string.
// The format of the string is the format of the lib_prot::FieldId's only field
bool lib_prot::FieldId_ReadStrptrMaybe(lib_prot::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && lib_prot::value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- lib_prot.FieldId..Print
// print string representation of lib_prot::FieldId to string LHS, no header -- cprint:lib_prot.FieldId.String
void lib_prot::FieldId_Print(lib_prot::FieldId & row, algo::cstring &str) {
    lib_prot::value_Print(row, str);
}

// --- lib_prot...SizeCheck
inline static void lib_prot::SizeCheck() {
}
