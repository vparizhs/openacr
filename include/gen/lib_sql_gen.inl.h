//
// include/gen/lib_sql_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
inline lib_sql::FAttr::FAttr() {
    lib_sql::FAttr_Init(*this);
}

inline lib_sql::FAttr::~FAttr() {
    lib_sql::FAttr_Uninit(*this);
}


// --- lib_sql.FAttr..Init
// Set all fields to initial values.
inline void lib_sql::FAttr_Init(lib_sql::FAttr& attr) {
    attr.isbool = bool(false);
    attr.ind_attr_next = (lib_sql::FAttr*)-1; // (lib_sql.FDb.ind_attr) not-in-hash
}
inline lib_sql::trace::trace() {
}


// --- lib_sql.FDb.attr.EmptyQ
// Return true if index is empty
inline bool lib_sql::attr_EmptyQ() {
    return _db.attr_n == 0;
}

// --- lib_sql.FDb.attr.Find
// Look up row by row id. Return NULL if out of range
inline lib_sql::FAttr* lib_sql::attr_Find(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    lib_sql::FAttr *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.attr_n))) {
        retval = &_db.attr_lary[bsr][index];
    }
    return retval;
}

// --- lib_sql.FDb.attr.Last
// Return pointer to last element of array, or NULL if array is empty
inline lib_sql::FAttr* lib_sql::attr_Last() {
    return attr_Find(u64(_db.attr_n-1));
}

// --- lib_sql.FDb.attr.N
// Return number of items in the pool
inline i32 lib_sql::attr_N() {
    return _db.attr_n;
}

// --- lib_sql.FDb.attr.qFind
// 'quick' Access row by row id. No bounds checking.
inline lib_sql::FAttr& lib_sql::attr_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.attr_lary[bsr][index];
}

// --- lib_sql.FDb.ind_attr.EmptyQ
// Return true if hash is empty
inline bool lib_sql::ind_attr_EmptyQ() {
    return _db.ind_attr_n == 0;
}

// --- lib_sql.FDb.ind_attr.N
// Return number of items in the hash
inline i32 lib_sql::ind_attr_N() {
    return _db.ind_attr_n;
}

// --- lib_sql.FDb.attr_curs.Reset
// cursor points to valid item
inline void lib_sql::_db_attr_curs_Reset(_db_attr_curs &curs, lib_sql::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- lib_sql.FDb.attr_curs.ValidQ
// cursor points to valid item
inline bool lib_sql::_db_attr_curs_ValidQ(_db_attr_curs &curs) {
    return curs.index < _db.attr_n;
}

// --- lib_sql.FDb.attr_curs.Next
// proceed to next item
inline void lib_sql::_db_attr_curs_Next(_db_attr_curs &curs) {
    curs.index++;
}

// --- lib_sql.FDb.attr_curs.Access
// item access
inline lib_sql::FAttr& lib_sql::_db_attr_curs_Access(_db_attr_curs &curs) {
    return attr_qFind(u64(curs.index));
}
inline lib_sql::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline lib_sql::FieldId::FieldId(lib_sql_FieldIdEnum arg) { this->value = i32(arg); }
inline lib_sql::FieldId::FieldId() {
    lib_sql::FieldId_Init(*this);
}


// --- lib_sql.FieldId.value.GetEnum
// Get value of field as enum type
inline lib_sql_FieldIdEnum lib_sql::value_GetEnum(const lib_sql::FieldId& parent) {
    return lib_sql_FieldIdEnum(parent.value);
}

// --- lib_sql.FieldId.value.SetEnum
// Set value of field from enum type.
inline void lib_sql::value_SetEnum(lib_sql::FieldId& parent, lib_sql_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- lib_sql.FieldId.value.Cast
inline lib_sql::FieldId::operator lib_sql_FieldIdEnum () const {
    return lib_sql_FieldIdEnum((*this).value);
}

// --- lib_sql.FieldId..Init
// Set all fields to initial values.
inline void lib_sql::FieldId_Init(lib_sql::FieldId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_sql::trace &row) {// cfmt:lib_sql.trace.String
    lib_sql::trace_Print(const_cast<lib_sql::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_sql::FieldId &row) {// cfmt:lib_sql.FieldId.String
    lib_sql::FieldId_Print(const_cast<lib_sql::FieldId&>(row), str);
    return str;
}
