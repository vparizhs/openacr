//
// include/gen/atf_nrun_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
//#pragma endinclude
inline atf_nrun::trace::trace() {
}


// --- atf_nrun.FDb.fentry.EmptyQ
// Return true if index is empty
inline bool atf_nrun::fentry_EmptyQ() {
    return _db.fentry_n == 0;
}

// --- atf_nrun.FDb.fentry.Find
// Look up row by row id. Return NULL if out of range
inline atf_nrun::FEntry* atf_nrun::fentry_Find(u64 t) {
    atf_nrun::FEntry *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.fentry_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.fentry_lary[bsr][index];
    }
    return retval;
}

// --- atf_nrun.FDb.fentry.Last
// Return pointer to last element of array, or NULL if array is empty
inline atf_nrun::FEntry* atf_nrun::fentry_Last() {
    return fentry_Find(u64(_db.fentry_n-1));
}

// --- atf_nrun.FDb.fentry.N
// Return number of items in the pool
inline i32 atf_nrun::fentry_N() {
    return _db.fentry_n;
}

// --- atf_nrun.FDb.fentry.qFind
// 'quick' Access row by row id. No bounds checking.
inline atf_nrun::FEntry& atf_nrun::fentry_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.fentry_lary[bsr][index];
}

// --- atf_nrun.FDb.ind_running.EmptyQ
// Return true if hash is empty
inline bool atf_nrun::ind_running_EmptyQ() {
    return _db.ind_running_n == 0;
}

// --- atf_nrun.FDb.ind_running.N
// Return number of items in the hash
inline i32 atf_nrun::ind_running_N() {
    return _db.ind_running_n;
}

// --- atf_nrun.FDb.zd_todo.EmptyQ
// Return true if index is empty
inline bool atf_nrun::zd_todo_EmptyQ() {
    return _db.zd_todo_head == NULL;
}

// --- atf_nrun.FDb.zd_todo.First
// If index empty, return NULL. Otherwise return pointer to first element in index
inline atf_nrun::FEntry* atf_nrun::zd_todo_First() {
    atf_nrun::FEntry *row = NULL;
    row = _db.zd_todo_head;
    return row;
}

// --- atf_nrun.FDb.zd_todo.InLlistQ
// Return true if row is in the linked list, false otherwise
inline bool atf_nrun::zd_todo_InLlistQ(atf_nrun::FEntry& row) {
    bool result = false;
    result = !(row.zd_todo_next == (atf_nrun::FEntry*)-1);
    return result;
}

// --- atf_nrun.FDb.zd_todo.Last
// If index empty, return NULL. Otherwise return pointer to last element in index
inline atf_nrun::FEntry* atf_nrun::zd_todo_Last() {
    atf_nrun::FEntry *row = NULL;
    row = _db.zd_todo_tail;
    return row;
}

// --- atf_nrun.FDb.zd_todo.N
// Return number of items in the linked list
inline i32 atf_nrun::zd_todo_N() {
    return _db.zd_todo_n;
}

// --- atf_nrun.FDb.zd_todo.Next
// Return pointer to next element in the list
inline atf_nrun::FEntry* atf_nrun::zd_todo_Next(atf_nrun::FEntry &row) {
    return row.zd_todo_next;
}

// --- atf_nrun.FDb.zd_todo.Prev
// Return pointer to previous element in the list
inline atf_nrun::FEntry* atf_nrun::zd_todo_Prev(atf_nrun::FEntry &row) {
    return row.zd_todo_prev;
}

// --- atf_nrun.FDb.zd_todo.qLast
// Return reference to last element in the index. No bounds checking.
inline atf_nrun::FEntry& atf_nrun::zd_todo_qLast() {
    atf_nrun::FEntry *row = NULL;
    row = _db.zd_todo_tail;
    return *row;
}

// --- atf_nrun.FDb.fentry_curs.Reset
// cursor points to valid item
inline void atf_nrun::_db_fentry_curs_Reset(_db_fentry_curs &curs, atf_nrun::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- atf_nrun.FDb.fentry_curs.ValidQ
// cursor points to valid item
inline bool atf_nrun::_db_fentry_curs_ValidQ(_db_fentry_curs &curs) {
    return curs.index < _db.fentry_n;
}

// --- atf_nrun.FDb.fentry_curs.Next
// proceed to next item
inline void atf_nrun::_db_fentry_curs_Next(_db_fentry_curs &curs) {
    curs.index++;
}

// --- atf_nrun.FDb.fentry_curs.Access
// item access
inline atf_nrun::FEntry& atf_nrun::_db_fentry_curs_Access(_db_fentry_curs &curs) {
    return fentry_qFind(u64(curs.index));
}

// --- atf_nrun.FDb.zd_todo_curs.Reset
// cursor points to valid item
inline void atf_nrun::_db_zd_todo_curs_Reset(_db_zd_todo_curs &curs, atf_nrun::FDb &parent) {
    curs.row = parent.zd_todo_head;
}

// --- atf_nrun.FDb.zd_todo_curs.ValidQ
// cursor points to valid item
inline bool atf_nrun::_db_zd_todo_curs_ValidQ(_db_zd_todo_curs &curs) {
    return curs.row != NULL;
}

// --- atf_nrun.FDb.zd_todo_curs.Next
// proceed to next item
inline void atf_nrun::_db_zd_todo_curs_Next(_db_zd_todo_curs &curs) {
    curs.row = (*curs.row).zd_todo_next;
}

// --- atf_nrun.FDb.zd_todo_curs.Access
// item access
inline atf_nrun::FEntry& atf_nrun::_db_zd_todo_curs_Access(_db_zd_todo_curs &curs) {
    return *curs.row;
}
inline atf_nrun::FEntry::FEntry() {
    atf_nrun::FEntry_Init(*this);
}

inline atf_nrun::FEntry::~FEntry() {
    atf_nrun::FEntry_Uninit(*this);
}

inline atf_nrun::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline atf_nrun::FieldId::FieldId(atf_nrun_FieldIdEnum arg) { this->value = i32(arg); }
inline atf_nrun::FieldId::FieldId() {
    atf_nrun::FieldId_Init(*this);
}


// --- atf_nrun.FieldId.value.GetEnum
// Get value of field as enum type
inline atf_nrun_FieldIdEnum atf_nrun::value_GetEnum(const atf_nrun::FieldId& parent) {
    return atf_nrun_FieldIdEnum(parent.value);
}

// --- atf_nrun.FieldId.value.SetEnum
// Set value of field from enum type.
inline void atf_nrun::value_SetEnum(atf_nrun::FieldId& parent, atf_nrun_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- atf_nrun.FieldId.value.Cast
inline atf_nrun::FieldId::operator atf_nrun_FieldIdEnum () const {
    return atf_nrun_FieldIdEnum((*this).value);
}

// --- atf_nrun.FieldId..Init
// Set all fields to initial values.
inline void atf_nrun::FieldId_Init(atf_nrun::FieldId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_nrun::trace &row) {// cfmt:atf_nrun.trace.String
    atf_nrun::trace_Print(const_cast<atf_nrun::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const atf_nrun::FieldId &row) {// cfmt:atf_nrun.FieldId.String
    atf_nrun::FieldId_Print(const_cast<atf_nrun::FieldId&>(row), str);
    return str;
}
