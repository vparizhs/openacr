//
// include/gen/mdbg_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/dev_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/command_gen.inl.h"
//#pragma endinclude
inline mdbg::FBuilddir::FBuilddir() {
    mdbg::FBuilddir_Init(*this);
}

inline mdbg::FBuilddir::~FBuilddir() {
    mdbg::FBuilddir_Uninit(*this);
}


// --- mdbg.FBuilddir..Init
// Set all fields to initial values.
inline void mdbg::FBuilddir_Init(mdbg::FBuilddir& builddir) {
    builddir.cfg_c_builddir_in_ary = bool(false);
}
inline mdbg::FCfg::FCfg() {
    mdbg::FCfg_Init(*this);
}

inline mdbg::FCfg::~FCfg() {
    mdbg::FCfg_Uninit(*this);
}


// --- mdbg.FCfg.c_builddir.EmptyQ
// Return true if index is empty
inline bool mdbg::c_builddir_EmptyQ(mdbg::FCfg& cfg) {
    return cfg.c_builddir_n == 0;
}

// --- mdbg.FCfg.c_builddir.Find
// Look up row by row id. Return NULL if out of range
inline mdbg::FBuilddir* mdbg::c_builddir_Find(mdbg::FCfg& cfg, u32 t) {
    mdbg::FBuilddir *retval = NULL;
    u64 idx = t;
    u64 lim = cfg.c_builddir_n;
    if (idx < lim) {
        retval = cfg.c_builddir_elems[idx];
    }
    return retval;
}

// --- mdbg.FCfg.c_builddir.Getary
// Return array of pointers
inline algo::aryptr<mdbg::FBuilddir*> mdbg::c_builddir_Getary(mdbg::FCfg& cfg) {
    return algo::aryptr<mdbg::FBuilddir*>(cfg.c_builddir_elems, cfg.c_builddir_n);
}

// --- mdbg.FCfg.c_builddir.N
// Return number of items in the pointer array
inline i32 mdbg::c_builddir_N(const mdbg::FCfg& cfg) {
    return cfg.c_builddir_n;
}

// --- mdbg.FCfg.c_builddir.RemoveAll
// Empty the index. (The rows are not deleted)
inline void mdbg::c_builddir_RemoveAll(mdbg::FCfg& cfg) {
    for (u32 i = 0; i < cfg.c_builddir_n; i++) {
        // mark all elements as not-in-array
        cfg.c_builddir_elems[i]->cfg_c_builddir_in_ary = false;
    }
    cfg.c_builddir_n = 0;
}

// --- mdbg.FCfg.c_builddir_curs.Reset
inline void mdbg::cfg_c_builddir_curs_Reset(cfg_c_builddir_curs &curs, mdbg::FCfg &parent) {
    curs.elems = parent.c_builddir_elems;
    curs.n_elems = parent.c_builddir_n;
    curs.index = 0;
}

// --- mdbg.FCfg.c_builddir_curs.ValidQ
// cursor points to valid item
inline bool mdbg::cfg_c_builddir_curs_ValidQ(cfg_c_builddir_curs &curs) {
    return curs.index < curs.n_elems;
}

// --- mdbg.FCfg.c_builddir_curs.Next
// proceed to next item
inline void mdbg::cfg_c_builddir_curs_Next(cfg_c_builddir_curs &curs) {
    curs.index++;
}

// --- mdbg.FCfg.c_builddir_curs.Access
// item access
inline mdbg::FBuilddir& mdbg::cfg_c_builddir_curs_Access(cfg_c_builddir_curs &curs) {
    return *curs.elems[curs.index];
}

// --- mdbg.FCfg..Init
// Set all fields to initial values.
inline void mdbg::FCfg_Init(mdbg::FCfg& cfg) {
    cfg.c_builddir_elems = NULL; // (mdbg.FCfg.c_builddir)
    cfg.c_builddir_n = 0; // (mdbg.FCfg.c_builddir)
    cfg.c_builddir_max = 0; // (mdbg.FCfg.c_builddir)
    cfg.ind_cfg_next = (mdbg::FCfg*)-1; // (mdbg.FDb.ind_cfg) not-in-hash
}
inline mdbg::trace::trace() {
}


// --- mdbg.FDb.cfg.EmptyQ
// Return true if index is empty
inline bool mdbg::cfg_EmptyQ() {
    return _db.cfg_n == 0;
}

// --- mdbg.FDb.cfg.Find
// Look up row by row id. Return NULL if out of range
inline mdbg::FCfg* mdbg::cfg_Find(u64 t) {
    mdbg::FCfg *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.cfg_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.cfg_lary[bsr][index];
    }
    return retval;
}

// --- mdbg.FDb.cfg.Last
// Return pointer to last element of array, or NULL if array is empty
inline mdbg::FCfg* mdbg::cfg_Last() {
    return cfg_Find(u64(_db.cfg_n-1));
}

// --- mdbg.FDb.cfg.N
// Return number of items in the pool
inline i32 mdbg::cfg_N() {
    return _db.cfg_n;
}

// --- mdbg.FDb.cfg.qFind
// 'quick' Access row by row id. No bounds checking.
inline mdbg::FCfg& mdbg::cfg_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.cfg_lary[bsr][index];
}

// --- mdbg.FDb.ind_cfg.EmptyQ
// Return true if hash is empty
inline bool mdbg::ind_cfg_EmptyQ() {
    return _db.ind_cfg_n == 0;
}

// --- mdbg.FDb.ind_cfg.N
// Return number of items in the hash
inline i32 mdbg::ind_cfg_N() {
    return _db.ind_cfg_n;
}

// --- mdbg.FDb.builddir.EmptyQ
// Return true if index is empty
inline bool mdbg::builddir_EmptyQ() {
    return _db.builddir_n == 0;
}

// --- mdbg.FDb.builddir.Find
// Look up row by row id. Return NULL if out of range
inline mdbg::FBuilddir* mdbg::builddir_Find(u64 t) {
    mdbg::FBuilddir *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.builddir_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.builddir_lary[bsr][index];
    }
    return retval;
}

// --- mdbg.FDb.builddir.Last
// Return pointer to last element of array, or NULL if array is empty
inline mdbg::FBuilddir* mdbg::builddir_Last() {
    return builddir_Find(u64(_db.builddir_n-1));
}

// --- mdbg.FDb.builddir.N
// Return number of items in the pool
inline i32 mdbg::builddir_N() {
    return _db.builddir_n;
}

// --- mdbg.FDb.builddir.qFind
// 'quick' Access row by row id. No bounds checking.
inline mdbg::FBuilddir& mdbg::builddir_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.builddir_lary[bsr][index];
}

// --- mdbg.FDb.cfg_curs.Reset
// cursor points to valid item
inline void mdbg::_db_cfg_curs_Reset(_db_cfg_curs &curs, mdbg::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- mdbg.FDb.cfg_curs.ValidQ
// cursor points to valid item
inline bool mdbg::_db_cfg_curs_ValidQ(_db_cfg_curs &curs) {
    return curs.index < _db.cfg_n;
}

// --- mdbg.FDb.cfg_curs.Next
// proceed to next item
inline void mdbg::_db_cfg_curs_Next(_db_cfg_curs &curs) {
    curs.index++;
}

// --- mdbg.FDb.cfg_curs.Access
// item access
inline mdbg::FCfg& mdbg::_db_cfg_curs_Access(_db_cfg_curs &curs) {
    return cfg_qFind(u64(curs.index));
}

// --- mdbg.FDb.builddir_curs.Reset
// cursor points to valid item
inline void mdbg::_db_builddir_curs_Reset(_db_builddir_curs &curs, mdbg::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- mdbg.FDb.builddir_curs.ValidQ
// cursor points to valid item
inline bool mdbg::_db_builddir_curs_ValidQ(_db_builddir_curs &curs) {
    return curs.index < _db.builddir_n;
}

// --- mdbg.FDb.builddir_curs.Next
// proceed to next item
inline void mdbg::_db_builddir_curs_Next(_db_builddir_curs &curs) {
    curs.index++;
}

// --- mdbg.FDb.builddir_curs.Access
// item access
inline mdbg::FBuilddir& mdbg::_db_builddir_curs_Access(_db_builddir_curs &curs) {
    return builddir_qFind(u64(curs.index));
}
inline mdbg::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline mdbg::FieldId::FieldId(mdbg_FieldIdEnum arg) { this->value = i32(arg); }
inline mdbg::FieldId::FieldId() {
    mdbg::FieldId_Init(*this);
}


// --- mdbg.FieldId.value.GetEnum
// Get value of field as enum type
inline mdbg_FieldIdEnum mdbg::value_GetEnum(const mdbg::FieldId& parent) {
    return mdbg_FieldIdEnum(parent.value);
}

// --- mdbg.FieldId.value.SetEnum
// Set value of field from enum type.
inline void mdbg::value_SetEnum(mdbg::FieldId& parent, mdbg_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- mdbg.FieldId.value.Cast
inline mdbg::FieldId::operator mdbg_FieldIdEnum () const {
    return mdbg_FieldIdEnum((*this).value);
}

// --- mdbg.FieldId..Init
// Set all fields to initial values.
inline void mdbg::FieldId_Init(mdbg::FieldId& parent) {
    parent.value = i32(-1);
}
inline mdbg::TableId::TableId(i32                            in_value)
    : value(in_value)
{
}
inline mdbg::TableId::TableId(mdbg_TableIdEnum arg) { this->value = i32(arg); }
inline mdbg::TableId::TableId() {
    mdbg::TableId_Init(*this);
}


// --- mdbg.TableId.value.GetEnum
// Get value of field as enum type
inline mdbg_TableIdEnum mdbg::value_GetEnum(const mdbg::TableId& parent) {
    return mdbg_TableIdEnum(parent.value);
}

// --- mdbg.TableId.value.SetEnum
// Set value of field from enum type.
inline void mdbg::value_SetEnum(mdbg::TableId& parent, mdbg_TableIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- mdbg.TableId.value.Cast
inline mdbg::TableId::operator mdbg_TableIdEnum () const {
    return mdbg_TableIdEnum((*this).value);
}

// --- mdbg.TableId..Init
// Set all fields to initial values.
inline void mdbg::TableId_Init(mdbg::TableId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const mdbg::trace &row) {// cfmt:mdbg.trace.String
    mdbg::trace_Print(const_cast<mdbg::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const mdbg::FieldId &row) {// cfmt:mdbg.FieldId.String
    mdbg::FieldId_Print(const_cast<mdbg::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const mdbg::TableId &row) {// cfmt:mdbg.TableId.String
    mdbg::TableId_Print(const_cast<mdbg::TableId&>(row), str);
    return str;
}
