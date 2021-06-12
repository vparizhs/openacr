//
// include/gen/lib_exec_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/command_gen.inl.h"
#include "include/gen/dev_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude
inline lib_exec::trace::trace() {
}


// --- lib_exec.FDb.syscmddep.EmptyQ
// Return true if index is empty
inline bool lib_exec::syscmddep_EmptyQ() {
    return _db.syscmddep_n == 0;
}

// --- lib_exec.FDb.syscmddep.Find
// Look up row by row id. Return NULL if out of range
inline lib_exec::FSyscmddep* lib_exec::syscmddep_Find(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    lib_exec::FSyscmddep *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.syscmddep_n))) {
        retval = &_db.syscmddep_lary[bsr][index];
    }
    return retval;
}

// --- lib_exec.FDb.syscmddep.Last
// Return pointer to last element of array, or NULL if array is empty
inline lib_exec::FSyscmddep* lib_exec::syscmddep_Last() {
    return syscmddep_Find(u64(_db.syscmddep_n-1));
}

// --- lib_exec.FDb.syscmddep.N
// Return number of items in the pool
inline i32 lib_exec::syscmddep_N() {
    return _db.syscmddep_n;
}

// --- lib_exec.FDb.syscmddep.qFind
// 'quick' Access row by row id. No bounds checking.
inline lib_exec::FSyscmddep& lib_exec::syscmddep_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.syscmddep_lary[bsr][index];
}

// --- lib_exec.FDb.syscmd.EmptyQ
// Return true if index is empty
inline bool lib_exec::syscmd_EmptyQ() {
    return _db.syscmd_n == 0;
}

// --- lib_exec.FDb.syscmd.Find
// Look up row by row id. Return NULL if out of range
inline lib_exec::FSyscmd* lib_exec::syscmd_Find(i32 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    lib_exec::FSyscmd *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.syscmd_n))) {
        retval = &_db.syscmd_lary[bsr][index];
    }
    return retval;
}

// --- lib_exec.FDb.syscmd.Last
// Return pointer to last element of array, or NULL if array is empty
inline lib_exec::FSyscmd* lib_exec::syscmd_Last() {
    return syscmd_Find(i32(_db.syscmd_n-1));
}

// --- lib_exec.FDb.syscmd.N
// Return number of items in the pool
inline i32 lib_exec::syscmd_N() {
    return _db.syscmd_n;
}

// --- lib_exec.FDb.syscmd.qFind
// 'quick' Access row by row id. No bounds checking.
inline lib_exec::FSyscmd& lib_exec::syscmd_qFind(i32 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.syscmd_lary[bsr][index];
}

// --- lib_exec.FDb.ind_running.EmptyQ
// Return true if hash is empty
inline bool lib_exec::ind_running_EmptyQ() {
    return _db.ind_running_n == 0;
}

// --- lib_exec.FDb.ind_running.N
// Return number of items in the hash
inline i32 lib_exec::ind_running_N() {
    return _db.ind_running_n;
}

// --- lib_exec.FDb.bh_syscmd.EmptyQ
// Return true if index is empty
inline bool lib_exec::bh_syscmd_EmptyQ() {
    return _db.bh_syscmd_n == 0;
}

// --- lib_exec.FDb.bh_syscmd.First
// If index empty, return NULL. Otherwise return pointer to first element in index
inline lib_exec::FSyscmd* lib_exec::bh_syscmd_First() {
    lib_exec::FSyscmd *row = NULL;
    if (_db.bh_syscmd_n > 0) {
        row = _db.bh_syscmd_elems[0];
    }
    return row;
}

// --- lib_exec.FDb.bh_syscmd.InBheapQ
// Return true if row is in index, false otherwise
inline bool lib_exec::bh_syscmd_InBheapQ(lib_exec::FSyscmd& row) {
    bool result = false;
    result = row.bh_syscmd_idx != -1;
    return result;
}

// --- lib_exec.FDb.bh_syscmd.N
// Return number of items in the heap
inline i32 lib_exec::bh_syscmd_N() {
    return _db.bh_syscmd_n;
}

// --- lib_exec.FDb.zd_started.EmptyQ
// Return true if index is empty
inline bool lib_exec::zd_started_EmptyQ() {
    return _db.zd_started_head == NULL;
}

// --- lib_exec.FDb.zd_started.First
// If index empty, return NULL. Otherwise return pointer to first element in index
inline lib_exec::FSyscmd* lib_exec::zd_started_First() {
    lib_exec::FSyscmd *row = NULL;
    row = _db.zd_started_head;
    return row;
}

// --- lib_exec.FDb.zd_started.InLlistQ
// Return true if row is in the linked list, false otherwise
inline bool lib_exec::zd_started_InLlistQ(lib_exec::FSyscmd& row) {
    bool result = false;
    result = !(row.zd_started_next == (lib_exec::FSyscmd*)-1);
    return result;
}

// --- lib_exec.FDb.zd_started.Last
// If index empty, return NULL. Otherwise return pointer to last element in index
inline lib_exec::FSyscmd* lib_exec::zd_started_Last() {
    lib_exec::FSyscmd *row = NULL;
    row = _db.zd_started_tail;
    return row;
}

// --- lib_exec.FDb.zd_started.N
// Return number of items in the linked list
inline i32 lib_exec::zd_started_N() {
    return _db.zd_started_n;
}

// --- lib_exec.FDb.zd_started.Next
// Return pointer to next element in the list
inline lib_exec::FSyscmd* lib_exec::zd_started_Next(lib_exec::FSyscmd &row) {
    return row.zd_started_next;
}

// --- lib_exec.FDb.zd_started.Prev
// Return pointer to previous element in the list
inline lib_exec::FSyscmd* lib_exec::zd_started_Prev(lib_exec::FSyscmd &row) {
    return row.zd_started_prev;
}

// --- lib_exec.FDb.zd_started.qLast
// Return reference to last element in the index. No bounds checking.
inline lib_exec::FSyscmd& lib_exec::zd_started_qLast() {
    lib_exec::FSyscmd *row = NULL;
    row = _db.zd_started_tail;
    return *row;
}

// --- lib_exec.FDb.syscmddep_curs.Reset
// cursor points to valid item
inline void lib_exec::_db_syscmddep_curs_Reset(_db_syscmddep_curs &curs, lib_exec::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- lib_exec.FDb.syscmddep_curs.ValidQ
// cursor points to valid item
inline bool lib_exec::_db_syscmddep_curs_ValidQ(_db_syscmddep_curs &curs) {
    return curs.index < _db.syscmddep_n;
}

// --- lib_exec.FDb.syscmddep_curs.Next
// proceed to next item
inline void lib_exec::_db_syscmddep_curs_Next(_db_syscmddep_curs &curs) {
    curs.index++;
}

// --- lib_exec.FDb.syscmddep_curs.Access
// item access
inline lib_exec::FSyscmddep& lib_exec::_db_syscmddep_curs_Access(_db_syscmddep_curs &curs) {
    return syscmddep_qFind(u64(curs.index));
}

// --- lib_exec.FDb.syscmd_curs.Reset
// cursor points to valid item
inline void lib_exec::_db_syscmd_curs_Reset(_db_syscmd_curs &curs, lib_exec::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- lib_exec.FDb.syscmd_curs.ValidQ
// cursor points to valid item
inline bool lib_exec::_db_syscmd_curs_ValidQ(_db_syscmd_curs &curs) {
    return curs.index < _db.syscmd_n;
}

// --- lib_exec.FDb.syscmd_curs.Next
// proceed to next item
inline void lib_exec::_db_syscmd_curs_Next(_db_syscmd_curs &curs) {
    curs.index++;
}

// --- lib_exec.FDb.syscmd_curs.Access
// item access
inline lib_exec::FSyscmd& lib_exec::_db_syscmd_curs_Access(_db_syscmd_curs &curs) {
    return syscmd_qFind(i32(curs.index));
}

// --- lib_exec.FDb.bh_syscmd_curs.Access
// Access current element. If not more elements, return NULL
inline lib_exec::FSyscmd& lib_exec::_db_bh_syscmd_curs_Access(_db_bh_syscmd_curs &curs) {
    return *curs.temp_elems[0];
}

// --- lib_exec.FDb.bh_syscmd_curs.ValidQ
// Return true if Access() will return non-NULL.
inline bool lib_exec::_db_bh_syscmd_curs_ValidQ(_db_bh_syscmd_curs &curs) {
    return curs.temp_n > 0;
}

// --- lib_exec.FDb.zd_started_curs.Reset
// cursor points to valid item
inline void lib_exec::_db_zd_started_curs_Reset(_db_zd_started_curs &curs, lib_exec::FDb &parent) {
    curs.row = parent.zd_started_head;
}

// --- lib_exec.FDb.zd_started_curs.ValidQ
// cursor points to valid item
inline bool lib_exec::_db_zd_started_curs_ValidQ(_db_zd_started_curs &curs) {
    return curs.row != NULL;
}

// --- lib_exec.FDb.zd_started_curs.Next
// proceed to next item
inline void lib_exec::_db_zd_started_curs_Next(_db_zd_started_curs &curs) {
    curs.row = (*curs.row).zd_started_next;
}

// --- lib_exec.FDb.zd_started_curs.Access
// item access
inline lib_exec::FSyscmd& lib_exec::_db_zd_started_curs_Access(_db_zd_started_curs &curs) {
    return *curs.row;
}
inline lib_exec::FSyscmd::FSyscmd() {
    lib_exec::FSyscmd_Init(*this);
}

inline lib_exec::FSyscmd::~FSyscmd() {
    lib_exec::FSyscmd_Uninit(*this);
}


// --- lib_exec.FSyscmd.c_prior.EmptyQ
// Return true if index is empty
inline bool lib_exec::c_prior_EmptyQ(lib_exec::FSyscmd& syscmd) {
    return syscmd.c_prior_n == 0;
}

// --- lib_exec.FSyscmd.c_prior.Find
// Look up row by row id. Return NULL if out of range
inline lib_exec::FSyscmddep* lib_exec::c_prior_Find(lib_exec::FSyscmd& syscmd, u32 t) {
    lib_exec::FSyscmddep *retval = NULL;
    u64 idx = t;
    u64 lim = syscmd.c_prior_n;
    if (idx < lim) {
        retval = syscmd.c_prior_elems[idx];
    }
    return retval;
}

// --- lib_exec.FSyscmd.c_prior.Getary
// Return array of pointers
inline algo::aryptr<lib_exec::FSyscmddep*> lib_exec::c_prior_Getary(lib_exec::FSyscmd& syscmd) {
    return algo::aryptr<lib_exec::FSyscmddep*>(syscmd.c_prior_elems, syscmd.c_prior_n);
}

// --- lib_exec.FSyscmd.c_prior.N
// Return number of items in the pointer array
inline i32 lib_exec::c_prior_N(const lib_exec::FSyscmd& syscmd) {
    return syscmd.c_prior_n;
}

// --- lib_exec.FSyscmd.c_prior.RemoveAll
// Empty the index. (The rows are not deleted)
inline void lib_exec::c_prior_RemoveAll(lib_exec::FSyscmd& syscmd) {
    for (u32 i = 0; i < syscmd.c_prior_n; i++) {
        // mark all elements as not-in-array
        syscmd.c_prior_elems[i]->syscmd_c_prior_in_ary = false;
    }
    syscmd.c_prior_n = 0;
}

// --- lib_exec.FSyscmd.c_next.EmptyQ
// Return true if index is empty
inline bool lib_exec::c_next_EmptyQ(lib_exec::FSyscmd& syscmd) {
    return syscmd.c_next_n == 0;
}

// --- lib_exec.FSyscmd.c_next.Find
// Look up row by row id. Return NULL if out of range
inline lib_exec::FSyscmddep* lib_exec::c_next_Find(lib_exec::FSyscmd& syscmd, u32 t) {
    lib_exec::FSyscmddep *retval = NULL;
    u64 idx = t;
    u64 lim = syscmd.c_next_n;
    if (idx < lim) {
        retval = syscmd.c_next_elems[idx];
    }
    return retval;
}

// --- lib_exec.FSyscmd.c_next.Getary
// Return array of pointers
inline algo::aryptr<lib_exec::FSyscmddep*> lib_exec::c_next_Getary(lib_exec::FSyscmd& syscmd) {
    return algo::aryptr<lib_exec::FSyscmddep*>(syscmd.c_next_elems, syscmd.c_next_n);
}

// --- lib_exec.FSyscmd.c_next.N
// Return number of items in the pointer array
inline i32 lib_exec::c_next_N(const lib_exec::FSyscmd& syscmd) {
    return syscmd.c_next_n;
}

// --- lib_exec.FSyscmd.c_next.RemoveAll
// Empty the index. (The rows are not deleted)
inline void lib_exec::c_next_RemoveAll(lib_exec::FSyscmd& syscmd) {
    for (u32 i = 0; i < syscmd.c_next_n; i++) {
        // mark all elements as not-in-array
        syscmd.c_next_elems[i]->syscmd_c_next_in_ary = false;
    }
    syscmd.c_next_n = 0;
}

// --- lib_exec.FSyscmd.c_prior_curs.Reset
inline void lib_exec::syscmd_c_prior_curs_Reset(syscmd_c_prior_curs &curs, lib_exec::FSyscmd &parent) {
    curs.elems = parent.c_prior_elems;
    curs.n_elems = parent.c_prior_n;
    curs.index = 0;
}

// --- lib_exec.FSyscmd.c_prior_curs.ValidQ
// cursor points to valid item
inline bool lib_exec::syscmd_c_prior_curs_ValidQ(syscmd_c_prior_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- lib_exec.FSyscmd.c_prior_curs.Next
// proceed to next item
inline void lib_exec::syscmd_c_prior_curs_Next(syscmd_c_prior_curs &curs) {
    curs.index++;
}

// --- lib_exec.FSyscmd.c_prior_curs.Access
// item access
inline lib_exec::FSyscmddep& lib_exec::syscmd_c_prior_curs_Access(syscmd_c_prior_curs &curs) {
    return *curs.elems[curs.index];
}

// --- lib_exec.FSyscmd.c_next_curs.Reset
inline void lib_exec::syscmd_c_next_curs_Reset(syscmd_c_next_curs &curs, lib_exec::FSyscmd &parent) {
    curs.elems = parent.c_next_elems;
    curs.n_elems = parent.c_next_n;
    curs.index = 0;
}

// --- lib_exec.FSyscmd.c_next_curs.ValidQ
// cursor points to valid item
inline bool lib_exec::syscmd_c_next_curs_ValidQ(syscmd_c_next_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- lib_exec.FSyscmd.c_next_curs.Next
// proceed to next item
inline void lib_exec::syscmd_c_next_curs_Next(syscmd_c_next_curs &curs) {
    curs.index++;
}

// --- lib_exec.FSyscmd.c_next_curs.Access
// item access
inline lib_exec::FSyscmddep& lib_exec::syscmd_c_next_curs_Access(syscmd_c_next_curs &curs) {
    return *curs.elems[curs.index];
}
inline lib_exec::FSyscmddep::FSyscmddep() {
    lib_exec::FSyscmddep_Init(*this);
}

inline lib_exec::FSyscmddep::~FSyscmddep() {
    lib_exec::FSyscmddep_Uninit(*this);
}


// --- lib_exec.FSyscmddep..Init
// Set all fields to initial values.
inline void lib_exec::FSyscmddep_Init(lib_exec::FSyscmddep& syscmddep) {
    syscmddep.child = i64(0);
    syscmddep.parent = i64(0);
    syscmddep.p_child = NULL;
    syscmddep.p_parent = NULL;
    syscmddep.syscmd_c_next_in_ary = bool(false);
    syscmddep.syscmd_c_prior_in_ary = bool(false);
}
inline lib_exec::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline lib_exec::FieldId::FieldId(lib_exec_FieldIdEnum arg) { this->value = i32(arg); }
inline lib_exec::FieldId::FieldId() {
    lib_exec::FieldId_Init(*this);
}


// --- lib_exec.FieldId.value.GetEnum
// Get value of field as enum type
inline lib_exec_FieldIdEnum lib_exec::value_GetEnum(const lib_exec::FieldId& parent) {
    return lib_exec_FieldIdEnum(parent.value);
}

// --- lib_exec.FieldId.value.SetEnum
// Set value of field from enum type.
inline void lib_exec::value_SetEnum(lib_exec::FieldId& parent, lib_exec_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- lib_exec.FieldId.value.Cast
inline lib_exec::FieldId::operator lib_exec_FieldIdEnum () const {
    return lib_exec_FieldIdEnum((*this).value);
}

// --- lib_exec.FieldId..Init
// Set all fields to initial values.
inline void lib_exec::FieldId_Init(lib_exec::FieldId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_exec::trace &row) {// cfmt:lib_exec.trace.String
    lib_exec::trace_Print(const_cast<lib_exec::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const lib_exec::FieldId &row) {// cfmt:lib_exec.FieldId.String
    lib_exec::FieldId_Print(const_cast<lib_exec::FieldId&>(row), str);
    return str;
}
