//
// include/gen/acr_my_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/dmmeta_gen.inl.h"
//#pragma endinclude
inline acr_my::trace::trace() {
}


// --- acr_my.FDb.ary_ns.EmptyQ
// Return true if index is empty
inline bool acr_my::ary_ns_EmptyQ() {
    return _db.ary_ns_n == 0;
}

// --- acr_my.FDb.ary_ns.Find
// Look up row by row id. Return NULL if out of range
inline algo::cstring* acr_my::ary_ns_Find(u64 t) {
    u64 idx = t;
    u64 lim = _db.ary_ns_n;
    if (idx >= lim) return NULL;
    return _db.ary_ns_elems + idx;
}

// --- acr_my.FDb.ary_ns.Getary
// Return array pointer by value
inline algo::aryptr<algo::cstring> acr_my::ary_ns_Getary() {
    return algo::aryptr<algo::cstring>(_db.ary_ns_elems, _db.ary_ns_n);
}

// --- acr_my.FDb.ary_ns.Last
// Return pointer to last element of array, or NULL if array is empty
inline algo::cstring* acr_my::ary_ns_Last() {
    return ary_ns_Find(u64(_db.ary_ns_n-1));
}

// --- acr_my.FDb.ary_ns.Max
// Return max. number of items in the array
inline i32 acr_my::ary_ns_Max() {
    return _db.ary_ns_max;
}

// --- acr_my.FDb.ary_ns.N
// Return number of items in the array
inline i32 acr_my::ary_ns_N() {
    return _db.ary_ns_n;
}

// --- acr_my.FDb.ary_ns.Reserve
// Make sure N *more* elements will fit in array. Process dies if out of memory
inline void acr_my::ary_ns_Reserve(int n) {
    u32 new_n = _db.ary_ns_n + n;
    if (UNLIKELY(new_n > _db.ary_ns_max)) {
        ary_ns_AbsReserve(new_n);
    }
}

// --- acr_my.FDb.ary_ns.qFind
// 'quick' Access row by row id. No bounds checking.
inline algo::cstring& acr_my::ary_ns_qFind(u64 t) {
    return _db.ary_ns_elems[t];
}

// --- acr_my.FDb.ary_ns.qLast
// Return reference to last element of array. No bounds checking
inline algo::cstring& acr_my::ary_ns_qLast() {
    return ary_ns_qFind(u64(_db.ary_ns_n-1));
}

// --- acr_my.FDb.ary_ns.rowid_Get
// Return row id of specified element
inline u64 acr_my::ary_ns_rowid_Get(algo::cstring &elem) {
    u64 id = &elem - _db.ary_ns_elems;
    return u64(id);
}

// --- acr_my.FDb.nsdb.EmptyQ
// Return true if index is empty
inline bool acr_my::nsdb_EmptyQ() {
    return _db.nsdb_n == 0;
}

// --- acr_my.FDb.nsdb.Find
// Look up row by row id. Return NULL if out of range
inline acr_my::FNsdb* acr_my::nsdb_Find(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    acr_my::FNsdb *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.nsdb_n))) {
        retval = &_db.nsdb_lary[bsr][index];
    }
    return retval;
}

// --- acr_my.FDb.nsdb.Last
// Return pointer to last element of array, or NULL if array is empty
inline acr_my::FNsdb* acr_my::nsdb_Last() {
    return nsdb_Find(u64(_db.nsdb_n-1));
}

// --- acr_my.FDb.nsdb.N
// Return number of items in the pool
inline i32 acr_my::nsdb_N() {
    return _db.nsdb_n;
}

// --- acr_my.FDb.nsdb.qFind
// 'quick' Access row by row id. No bounds checking.
inline acr_my::FNsdb& acr_my::nsdb_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.nsdb_lary[bsr][index];
}

// --- acr_my.FDb.ssimfile.EmptyQ
// Return true if index is empty
inline bool acr_my::ssimfile_EmptyQ() {
    return _db.ssimfile_n == 0;
}

// --- acr_my.FDb.ssimfile.Find
// Look up row by row id. Return NULL if out of range
inline acr_my::FSsimfile* acr_my::ssimfile_Find(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    acr_my::FSsimfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.ssimfile_n))) {
        retval = &_db.ssimfile_lary[bsr][index];
    }
    return retval;
}

// --- acr_my.FDb.ssimfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline acr_my::FSsimfile* acr_my::ssimfile_Last() {
    return ssimfile_Find(u64(_db.ssimfile_n-1));
}

// --- acr_my.FDb.ssimfile.N
// Return number of items in the pool
inline i32 acr_my::ssimfile_N() {
    return _db.ssimfile_n;
}

// --- acr_my.FDb.ssimfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline acr_my::FSsimfile& acr_my::ssimfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.ssimfile_lary[bsr][index];
}

// --- acr_my.FDb.ary_ns_curs.Next
// proceed to next item
inline void acr_my::_db_ary_ns_curs_Next(_db_ary_ns_curs &curs) {
    curs.index++;
}

// --- acr_my.FDb.ary_ns_curs.Reset
inline void acr_my::_db_ary_ns_curs_Reset(_db_ary_ns_curs &curs, acr_my::FDb &parent) {
    curs.elems = parent.ary_ns_elems;
    curs.n_elems = parent.ary_ns_n;
    curs.index = 0;
}

// --- acr_my.FDb.ary_ns_curs.ValidQ
// cursor points to valid item
inline bool acr_my::_db_ary_ns_curs_ValidQ(_db_ary_ns_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- acr_my.FDb.ary_ns_curs.Access
// item access
inline algo::cstring& acr_my::_db_ary_ns_curs_Access(_db_ary_ns_curs &curs) {
    return curs.elems[curs.index];
}

// --- acr_my.FDb.nsdb_curs.Reset
// cursor points to valid item
inline void acr_my::_db_nsdb_curs_Reset(_db_nsdb_curs &curs, acr_my::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- acr_my.FDb.nsdb_curs.ValidQ
// cursor points to valid item
inline bool acr_my::_db_nsdb_curs_ValidQ(_db_nsdb_curs &curs) {
    return curs.index < _db.nsdb_n;
}

// --- acr_my.FDb.nsdb_curs.Next
// proceed to next item
inline void acr_my::_db_nsdb_curs_Next(_db_nsdb_curs &curs) {
    curs.index++;
}

// --- acr_my.FDb.nsdb_curs.Access
// item access
inline acr_my::FNsdb& acr_my::_db_nsdb_curs_Access(_db_nsdb_curs &curs) {
    return nsdb_qFind(u64(curs.index));
}

// --- acr_my.FDb.ssimfile_curs.Reset
// cursor points to valid item
inline void acr_my::_db_ssimfile_curs_Reset(_db_ssimfile_curs &curs, acr_my::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- acr_my.FDb.ssimfile_curs.ValidQ
// cursor points to valid item
inline bool acr_my::_db_ssimfile_curs_ValidQ(_db_ssimfile_curs &curs) {
    return curs.index < _db.ssimfile_n;
}

// --- acr_my.FDb.ssimfile_curs.Next
// proceed to next item
inline void acr_my::_db_ssimfile_curs_Next(_db_ssimfile_curs &curs) {
    curs.index++;
}

// --- acr_my.FDb.ssimfile_curs.Access
// item access
inline acr_my::FSsimfile& acr_my::_db_ssimfile_curs_Access(_db_ssimfile_curs &curs) {
    return ssimfile_qFind(u64(curs.index));
}
inline acr_my::FNsdb::FNsdb() {
    acr_my::FNsdb_Init(*this);
}


// --- acr_my.FNsdb..Init
// Set all fields to initial values.
inline void acr_my::FNsdb_Init(acr_my::FNsdb& nsdb) {
    nsdb.select = bool(false);
}
inline acr_my::FSsimfile::FSsimfile() {
}

inline acr_my::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline acr_my::FieldId::FieldId(acr_my_FieldIdEnum arg) { this->value = i32(arg); }
inline acr_my::FieldId::FieldId() {
    acr_my::FieldId_Init(*this);
}


// --- acr_my.FieldId.value.GetEnum
// Get value of field as enum type
inline acr_my_FieldIdEnum acr_my::value_GetEnum(const acr_my::FieldId& parent) {
    return acr_my_FieldIdEnum(parent.value);
}

// --- acr_my.FieldId.value.SetEnum
// Set value of field from enum type.
inline void acr_my::value_SetEnum(acr_my::FieldId& parent, acr_my_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- acr_my.FieldId.value.Cast
inline acr_my::FieldId::operator acr_my_FieldIdEnum () const {
    return acr_my_FieldIdEnum((*this).value);
}

// --- acr_my.FieldId..Init
// Set all fields to initial values.
inline void acr_my::FieldId_Init(acr_my::FieldId& parent) {
    parent.value = i32(-1);
}
inline acr_my::TableId::TableId(i32                            in_value)
    : value(in_value)
{
}
inline acr_my::TableId::TableId(acr_my_TableIdEnum arg) { this->value = i32(arg); }
inline acr_my::TableId::TableId() {
    acr_my::TableId_Init(*this);
}


// --- acr_my.TableId.value.GetEnum
// Get value of field as enum type
inline acr_my_TableIdEnum acr_my::value_GetEnum(const acr_my::TableId& parent) {
    return acr_my_TableIdEnum(parent.value);
}

// --- acr_my.TableId.value.SetEnum
// Set value of field from enum type.
inline void acr_my::value_SetEnum(acr_my::TableId& parent, acr_my_TableIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- acr_my.TableId.value.Cast
inline acr_my::TableId::operator acr_my_TableIdEnum () const {
    return acr_my_TableIdEnum((*this).value);
}

// --- acr_my.TableId..Init
// Set all fields to initial values.
inline void acr_my::TableId_Init(acr_my::TableId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const acr_my::trace &row) {// cfmt:acr_my.trace.String
    acr_my::trace_Print(const_cast<acr_my::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const acr_my::FieldId &row) {// cfmt:acr_my.FieldId.String
    acr_my::FieldId_Print(const_cast<acr_my::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const acr_my::TableId &row) {// cfmt:acr_my.TableId.String
    acr_my::TableId_Print(const_cast<acr_my::TableId&>(row), str);
    return str;
}
