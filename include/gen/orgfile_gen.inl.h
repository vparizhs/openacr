//
// include/gen/orgfile_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/command_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/dev_gen.inl.h"
//#pragma endinclude
inline orgfile::trace::trace() {
}


// --- orgfile.FDb.ind_filename.EmptyQ
// Return true if hash is empty
inline bool orgfile::ind_filename_EmptyQ() {
    return _db.ind_filename_n == 0;
}

// --- orgfile.FDb.ind_filename.N
// Return number of items in the hash
inline i32 orgfile::ind_filename_N() {
    return _db.ind_filename_n;
}

// --- orgfile.FDb.filehash.EmptyQ
// Return true if index is empty
inline bool orgfile::filehash_EmptyQ() {
    return _db.filehash_n == 0;
}

// --- orgfile.FDb.filehash.Find
// Look up row by row id. Return NULL if out of range
inline orgfile::FFilehash* orgfile::filehash_Find(u64 t) {
    orgfile::FFilehash *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.filehash_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.filehash_lary[bsr][index];
    }
    return retval;
}

// --- orgfile.FDb.filehash.Last
// Return pointer to last element of array, or NULL if array is empty
inline orgfile::FFilehash* orgfile::filehash_Last() {
    return filehash_Find(u64(_db.filehash_n-1));
}

// --- orgfile.FDb.filehash.N
// Return number of items in the pool
inline i32 orgfile::filehash_N() {
    return _db.filehash_n;
}

// --- orgfile.FDb.filehash.qFind
// 'quick' Access row by row id. No bounds checking.
inline orgfile::FFilehash& orgfile::filehash_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.filehash_lary[bsr][index];
}

// --- orgfile.FDb.ind_filehash.EmptyQ
// Return true if hash is empty
inline bool orgfile::ind_filehash_EmptyQ() {
    return _db.ind_filehash_n == 0;
}

// --- orgfile.FDb.ind_filehash.N
// Return number of items in the hash
inline i32 orgfile::ind_filehash_N() {
    return _db.ind_filehash_n;
}

// --- orgfile.FDb.timefmt.EmptyQ
// Return true if index is empty
inline bool orgfile::timefmt_EmptyQ() {
    return _db.timefmt_n == 0;
}

// --- orgfile.FDb.timefmt.Find
// Look up row by row id. Return NULL if out of range
inline orgfile::FTimefmt* orgfile::timefmt_Find(u64 t) {
    orgfile::FTimefmt *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.timefmt_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.timefmt_lary[bsr][index];
    }
    return retval;
}

// --- orgfile.FDb.timefmt.Last
// Return pointer to last element of array, or NULL if array is empty
inline orgfile::FTimefmt* orgfile::timefmt_Last() {
    return timefmt_Find(u64(_db.timefmt_n-1));
}

// --- orgfile.FDb.timefmt.N
// Return number of items in the pool
inline i32 orgfile::timefmt_N() {
    return _db.timefmt_n;
}

// --- orgfile.FDb.timefmt.qFind
// 'quick' Access row by row id. No bounds checking.
inline orgfile::FTimefmt& orgfile::timefmt_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.timefmt_lary[bsr][index];
}

// --- orgfile.FDb.filehash_curs.Reset
// cursor points to valid item
inline void orgfile::_db_filehash_curs_Reset(_db_filehash_curs &curs, orgfile::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- orgfile.FDb.filehash_curs.ValidQ
// cursor points to valid item
inline bool orgfile::_db_filehash_curs_ValidQ(_db_filehash_curs &curs) {
    return curs.index < _db.filehash_n;
}

// --- orgfile.FDb.filehash_curs.Next
// proceed to next item
inline void orgfile::_db_filehash_curs_Next(_db_filehash_curs &curs) {
    curs.index++;
}

// --- orgfile.FDb.filehash_curs.Access
// item access
inline orgfile::FFilehash& orgfile::_db_filehash_curs_Access(_db_filehash_curs &curs) {
    return filehash_qFind(u64(curs.index));
}

// --- orgfile.FDb.timefmt_curs.Reset
// cursor points to valid item
inline void orgfile::_db_timefmt_curs_Reset(_db_timefmt_curs &curs, orgfile::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- orgfile.FDb.timefmt_curs.ValidQ
// cursor points to valid item
inline bool orgfile::_db_timefmt_curs_ValidQ(_db_timefmt_curs &curs) {
    return curs.index < _db.timefmt_n;
}

// --- orgfile.FDb.timefmt_curs.Next
// proceed to next item
inline void orgfile::_db_timefmt_curs_Next(_db_timefmt_curs &curs) {
    curs.index++;
}

// --- orgfile.FDb.timefmt_curs.Access
// item access
inline orgfile::FTimefmt& orgfile::_db_timefmt_curs_Access(_db_timefmt_curs &curs) {
    return timefmt_qFind(u64(curs.index));
}
inline orgfile::FFilehash::FFilehash() {
    orgfile::FFilehash_Init(*this);
}

inline orgfile::FFilehash::~FFilehash() {
    orgfile::FFilehash_Uninit(*this);
}


// --- orgfile.FFilehash.c_filename.EmptyQ
// Return true if index is empty
inline bool orgfile::c_filename_EmptyQ(orgfile::FFilehash& filehash) {
    return filehash.c_filename_n == 0;
}

// --- orgfile.FFilehash.c_filename.Find
// Look up row by row id. Return NULL if out of range
inline orgfile::FFilename* orgfile::c_filename_Find(orgfile::FFilehash& filehash, u32 t) {
    orgfile::FFilename *retval = NULL;
    u64 idx = t;
    u64 lim = filehash.c_filename_n;
    if (idx < lim) {
        retval = filehash.c_filename_elems[idx];
    }
    return retval;
}

// --- orgfile.FFilehash.c_filename.Getary
// Return array of pointers
inline algo::aryptr<orgfile::FFilename*> orgfile::c_filename_Getary(orgfile::FFilehash& filehash) {
    return algo::aryptr<orgfile::FFilename*>(filehash.c_filename_elems, filehash.c_filename_n);
}

// --- orgfile.FFilehash.c_filename.N
// Return number of items in the pointer array
inline i32 orgfile::c_filename_N(const orgfile::FFilehash& filehash) {
    return filehash.c_filename_n;
}

// --- orgfile.FFilehash.c_filename.RemoveAll
// Empty the index. (The rows are not deleted)
inline void orgfile::c_filename_RemoveAll(orgfile::FFilehash& filehash) {
    for (u32 i = 0; i < filehash.c_filename_n; i++) {
        // mark all elements as not-in-array
        filehash.c_filename_elems[i]->filehash_c_filename_in_ary = false;
    }
    filehash.c_filename_n = 0;
}

// --- orgfile.FFilehash..Init
// Set all fields to initial values.
inline void orgfile::FFilehash_Init(orgfile::FFilehash& filehash) {
    filehash.c_filename_elems = NULL; // (orgfile.FFilehash.c_filename)
    filehash.c_filename_n = 0; // (orgfile.FFilehash.c_filename)
    filehash.c_filename_max = 0; // (orgfile.FFilehash.c_filename)
    filehash.ind_filehash_next = (orgfile::FFilehash*)-1; // (orgfile.FDb.ind_filehash) not-in-hash
}

// --- orgfile.FFilehash.c_filename_curs.Reset
inline void orgfile::filehash_c_filename_curs_Reset(filehash_c_filename_curs &curs, orgfile::FFilehash &parent) {
    curs.elems = parent.c_filename_elems;
    curs.n_elems = parent.c_filename_n;
    curs.index = 0;
}

// --- orgfile.FFilehash.c_filename_curs.ValidQ
// cursor points to valid item
inline bool orgfile::filehash_c_filename_curs_ValidQ(filehash_c_filename_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- orgfile.FFilehash.c_filename_curs.Next
// proceed to next item
inline void orgfile::filehash_c_filename_curs_Next(filehash_c_filename_curs &curs) {
    curs.index++;
}

// --- orgfile.FFilehash.c_filename_curs.Access
// item access
inline orgfile::FFilename& orgfile::filehash_c_filename_curs_Access(filehash_c_filename_curs &curs) {
    return *curs.elems[curs.index];
}
inline orgfile::FFilename::FFilename() {
    orgfile::FFilename_Init(*this);
}

inline orgfile::FFilename::~FFilename() {
    orgfile::FFilename_Uninit(*this);
}


// --- orgfile.FFilename..Init
// Set all fields to initial values.
inline void orgfile::FFilename_Init(orgfile::FFilename& filename) {
    filename.p_filehash = NULL;
    filename.filehash_c_filename_in_ary = bool(false);
    filename.filename_next = (orgfile::FFilename*)-1; // (orgfile.FDb.filename) not-in-tpool's freelist
    filename.ind_filename_next = (orgfile::FFilename*)-1; // (orgfile.FDb.ind_filename) not-in-hash
}
inline orgfile::FTimefmt::FTimefmt() {
    orgfile::FTimefmt_Init(*this);
}


// --- orgfile.FTimefmt..Init
// Set all fields to initial values.
inline void orgfile::FTimefmt_Init(orgfile::FTimefmt& timefmt) {
    timefmt.dirname = bool(false);
}
inline orgfile::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline orgfile::FieldId::FieldId(orgfile_FieldIdEnum arg) { this->value = i32(arg); }
inline orgfile::FieldId::FieldId() {
    orgfile::FieldId_Init(*this);
}


// --- orgfile.FieldId.value.GetEnum
// Get value of field as enum type
inline orgfile_FieldIdEnum orgfile::value_GetEnum(const orgfile::FieldId& parent) {
    return orgfile_FieldIdEnum(parent.value);
}

// --- orgfile.FieldId.value.SetEnum
// Set value of field from enum type.
inline void orgfile::value_SetEnum(orgfile::FieldId& parent, orgfile_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- orgfile.FieldId.value.Cast
inline orgfile::FieldId::operator orgfile_FieldIdEnum () const {
    return orgfile_FieldIdEnum((*this).value);
}

// --- orgfile.FieldId..Init
// Set all fields to initial values.
inline void orgfile::FieldId_Init(orgfile::FieldId& parent) {
    parent.value = i32(-1);
}
inline orgfile::TableId::TableId(i32                            in_value)
    : value(in_value)
{
}
inline orgfile::TableId::TableId(orgfile_TableIdEnum arg) { this->value = i32(arg); }
inline orgfile::TableId::TableId() {
    orgfile::TableId_Init(*this);
}


// --- orgfile.TableId.value.GetEnum
// Get value of field as enum type
inline orgfile_TableIdEnum orgfile::value_GetEnum(const orgfile::TableId& parent) {
    return orgfile_TableIdEnum(parent.value);
}

// --- orgfile.TableId.value.SetEnum
// Set value of field from enum type.
inline void orgfile::value_SetEnum(orgfile::TableId& parent, orgfile_TableIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- orgfile.TableId.value.Cast
inline orgfile::TableId::operator orgfile_TableIdEnum () const {
    return orgfile_TableIdEnum((*this).value);
}

// --- orgfile.TableId..Init
// Set all fields to initial values.
inline void orgfile::TableId_Init(orgfile::TableId& parent) {
    parent.value = i32(-1);
}
inline orgfile::dedup::dedup() {
}

inline orgfile::move::move() {
}


inline algo::cstring &algo::operator <<(algo::cstring &str, const orgfile::trace &row) {// cfmt:orgfile.trace.String
    orgfile::trace_Print(const_cast<orgfile::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const orgfile::FieldId &row) {// cfmt:orgfile.FieldId.String
    orgfile::FieldId_Print(const_cast<orgfile::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const orgfile::TableId &row) {// cfmt:orgfile.TableId.String
    orgfile::TableId_Print(const_cast<orgfile::TableId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const orgfile::dedup &row) {// cfmt:orgfile.dedup.String
    orgfile::dedup_Print(const_cast<orgfile::dedup&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const orgfile::move &row) {// cfmt:orgfile.move.String
    orgfile::move_Print(const_cast<orgfile::move&>(row), str);
    return str;
}
