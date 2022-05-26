//
// include/gen/src_lim_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/dev_gen.inl.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/algo_lib_gen.inl.h"
#include "include/gen/command_gen.inl.h"
//#pragma endinclude
inline src_lim::FBadline::FBadline() {
    src_lim::FBadline_Init(*this);
}


// --- src_lim.FBadline..Init
// Set all fields to initial values.
inline void src_lim::FBadline_Init(src_lim::FBadline& badline) {
    badline.select = bool(false);
}
inline src_lim::trace::trace() {
}


// --- src_lim.FDb.include.EmptyQ
// Return true if index is empty
inline bool src_lim::include_EmptyQ() {
    return _db.include_n == 0;
}

// --- src_lim.FDb.include.Find
// Look up row by row id. Return NULL if out of range
inline src_lim::FInclude* src_lim::include_Find(u64 t) {
    src_lim::FInclude *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.include_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.include_lary[bsr][index];
    }
    return retval;
}

// --- src_lim.FDb.include.Last
// Return pointer to last element of array, or NULL if array is empty
inline src_lim::FInclude* src_lim::include_Last() {
    return include_Find(u64(_db.include_n-1));
}

// --- src_lim.FDb.include.N
// Return number of items in the pool
inline i32 src_lim::include_N() {
    return _db.include_n;
}

// --- src_lim.FDb.include.qFind
// 'quick' Access row by row id. No bounds checking.
inline src_lim::FInclude& src_lim::include_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.include_lary[bsr][index];
}

// --- src_lim.FDb.linelim.EmptyQ
// Return true if index is empty
inline bool src_lim::linelim_EmptyQ() {
    return _db.linelim_n == 0;
}

// --- src_lim.FDb.linelim.Find
// Look up row by row id. Return NULL if out of range
inline src_lim::FLinelim* src_lim::linelim_Find(u64 t) {
    src_lim::FLinelim *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.linelim_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.linelim_lary[bsr][index];
    }
    return retval;
}

// --- src_lim.FDb.linelim.Last
// Return pointer to last element of array, or NULL if array is empty
inline src_lim::FLinelim* src_lim::linelim_Last() {
    return linelim_Find(u64(_db.linelim_n-1));
}

// --- src_lim.FDb.linelim.N
// Return number of items in the pool
inline i32 src_lim::linelim_N() {
    return _db.linelim_n;
}

// --- src_lim.FDb.linelim.qFind
// 'quick' Access row by row id. No bounds checking.
inline src_lim::FLinelim& src_lim::linelim_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.linelim_lary[bsr][index];
}

// --- src_lim.FDb.targsrc.EmptyQ
// Return true if index is empty
inline bool src_lim::targsrc_EmptyQ() {
    return _db.targsrc_n == 0;
}

// --- src_lim.FDb.targsrc.Find
// Look up row by row id. Return NULL if out of range
inline src_lim::FTargsrc* src_lim::targsrc_Find(u64 t) {
    src_lim::FTargsrc *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.targsrc_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.targsrc_lary[bsr][index];
    }
    return retval;
}

// --- src_lim.FDb.targsrc.Last
// Return pointer to last element of array, or NULL if array is empty
inline src_lim::FTargsrc* src_lim::targsrc_Last() {
    return targsrc_Find(u64(_db.targsrc_n-1));
}

// --- src_lim.FDb.targsrc.N
// Return number of items in the pool
inline i32 src_lim::targsrc_N() {
    return _db.targsrc_n;
}

// --- src_lim.FDb.targsrc.qFind
// 'quick' Access row by row id. No bounds checking.
inline src_lim::FTargsrc& src_lim::targsrc_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.targsrc_lary[bsr][index];
}

// --- src_lim.FDb.gitfile.EmptyQ
// Return true if index is empty
inline bool src_lim::gitfile_EmptyQ() {
    return _db.gitfile_n == 0;
}

// --- src_lim.FDb.gitfile.Find
// Look up row by row id. Return NULL if out of range
inline src_lim::FGitfile* src_lim::gitfile_Find(u64 t) {
    src_lim::FGitfile *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.gitfile_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.gitfile_lary[bsr][index];
    }
    return retval;
}

// --- src_lim.FDb.gitfile.Last
// Return pointer to last element of array, or NULL if array is empty
inline src_lim::FGitfile* src_lim::gitfile_Last() {
    return gitfile_Find(u64(_db.gitfile_n-1));
}

// --- src_lim.FDb.gitfile.N
// Return number of items in the pool
inline i32 src_lim::gitfile_N() {
    return _db.gitfile_n;
}

// --- src_lim.FDb.gitfile.qFind
// 'quick' Access row by row id. No bounds checking.
inline src_lim::FGitfile& src_lim::gitfile_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.gitfile_lary[bsr][index];
}

// --- src_lim.FDb.ind_gitfile.EmptyQ
// Return true if hash is empty
inline bool src_lim::ind_gitfile_EmptyQ() {
    return _db.ind_gitfile_n == 0;
}

// --- src_lim.FDb.ind_gitfile.N
// Return number of items in the hash
inline i32 src_lim::ind_gitfile_N() {
    return _db.ind_gitfile_n;
}

// --- src_lim.FDb.badline.EmptyQ
// Return true if index is empty
inline bool src_lim::badline_EmptyQ() {
    return _db.badline_n == 0;
}

// --- src_lim.FDb.badline.Find
// Look up row by row id. Return NULL if out of range
inline src_lim::FBadline* src_lim::badline_Find(u64 t) {
    src_lim::FBadline *retval = NULL;
    if (LIKELY(u64(t) < u64(_db.badline_n))) {
        u64 x = t + 1;
        u64 bsr   = algo::u64_BitScanReverse(x);
        u64 base  = u64(1)<<bsr;
        u64 index = x-base;
        retval = &_db.badline_lary[bsr][index];
    }
    return retval;
}

// --- src_lim.FDb.badline.Last
// Return pointer to last element of array, or NULL if array is empty
inline src_lim::FBadline* src_lim::badline_Last() {
    return badline_Find(u64(_db.badline_n-1));
}

// --- src_lim.FDb.badline.N
// Return number of items in the pool
inline i32 src_lim::badline_N() {
    return _db.badline_n;
}

// --- src_lim.FDb.badline.qFind
// 'quick' Access row by row id. No bounds checking.
inline src_lim::FBadline& src_lim::badline_qFind(u64 t) {
    u64 x = t + 1;
    u64 bsr   = algo::u64_BitScanReverse(x);
    u64 base  = u64(1)<<bsr;
    u64 index = x-base;
    return _db.badline_lary[bsr][index];
}

// --- src_lim.FDb.include_curs.Reset
// cursor points to valid item
inline void src_lim::_db_include_curs_Reset(_db_include_curs &curs, src_lim::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- src_lim.FDb.include_curs.ValidQ
// cursor points to valid item
inline bool src_lim::_db_include_curs_ValidQ(_db_include_curs &curs) {
    return curs.index < _db.include_n;
}

// --- src_lim.FDb.include_curs.Next
// proceed to next item
inline void src_lim::_db_include_curs_Next(_db_include_curs &curs) {
    curs.index++;
}

// --- src_lim.FDb.include_curs.Access
// item access
inline src_lim::FInclude& src_lim::_db_include_curs_Access(_db_include_curs &curs) {
    return include_qFind(u64(curs.index));
}

// --- src_lim.FDb.linelim_curs.Reset
// cursor points to valid item
inline void src_lim::_db_linelim_curs_Reset(_db_linelim_curs &curs, src_lim::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- src_lim.FDb.linelim_curs.ValidQ
// cursor points to valid item
inline bool src_lim::_db_linelim_curs_ValidQ(_db_linelim_curs &curs) {
    return curs.index < _db.linelim_n;
}

// --- src_lim.FDb.linelim_curs.Next
// proceed to next item
inline void src_lim::_db_linelim_curs_Next(_db_linelim_curs &curs) {
    curs.index++;
}

// --- src_lim.FDb.linelim_curs.Access
// item access
inline src_lim::FLinelim& src_lim::_db_linelim_curs_Access(_db_linelim_curs &curs) {
    return linelim_qFind(u64(curs.index));
}

// --- src_lim.FDb.targsrc_curs.Reset
// cursor points to valid item
inline void src_lim::_db_targsrc_curs_Reset(_db_targsrc_curs &curs, src_lim::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- src_lim.FDb.targsrc_curs.ValidQ
// cursor points to valid item
inline bool src_lim::_db_targsrc_curs_ValidQ(_db_targsrc_curs &curs) {
    return curs.index < _db.targsrc_n;
}

// --- src_lim.FDb.targsrc_curs.Next
// proceed to next item
inline void src_lim::_db_targsrc_curs_Next(_db_targsrc_curs &curs) {
    curs.index++;
}

// --- src_lim.FDb.targsrc_curs.Access
// item access
inline src_lim::FTargsrc& src_lim::_db_targsrc_curs_Access(_db_targsrc_curs &curs) {
    return targsrc_qFind(u64(curs.index));
}

// --- src_lim.FDb.gitfile_curs.Reset
// cursor points to valid item
inline void src_lim::_db_gitfile_curs_Reset(_db_gitfile_curs &curs, src_lim::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- src_lim.FDb.gitfile_curs.ValidQ
// cursor points to valid item
inline bool src_lim::_db_gitfile_curs_ValidQ(_db_gitfile_curs &curs) {
    return curs.index < _db.gitfile_n;
}

// --- src_lim.FDb.gitfile_curs.Next
// proceed to next item
inline void src_lim::_db_gitfile_curs_Next(_db_gitfile_curs &curs) {
    curs.index++;
}

// --- src_lim.FDb.gitfile_curs.Access
// item access
inline src_lim::FGitfile& src_lim::_db_gitfile_curs_Access(_db_gitfile_curs &curs) {
    return gitfile_qFind(u64(curs.index));
}

// --- src_lim.FDb.badline_curs.Reset
// cursor points to valid item
inline void src_lim::_db_badline_curs_Reset(_db_badline_curs &curs, src_lim::FDb &parent) {
    curs.parent = &parent;
    curs.index = 0;
}

// --- src_lim.FDb.badline_curs.ValidQ
// cursor points to valid item
inline bool src_lim::_db_badline_curs_ValidQ(_db_badline_curs &curs) {
    return curs.index < _db.badline_n;
}

// --- src_lim.FDb.badline_curs.Next
// proceed to next item
inline void src_lim::_db_badline_curs_Next(_db_badline_curs &curs) {
    curs.index++;
}

// --- src_lim.FDb.badline_curs.Access
// item access
inline src_lim::FBadline& src_lim::_db_badline_curs_Access(_db_badline_curs &curs) {
    return badline_qFind(u64(curs.index));
}
inline src_lim::FGitfile::FGitfile() {
    src_lim::FGitfile_Init(*this);
}

inline src_lim::FGitfile::~FGitfile() {
    src_lim::FGitfile_Uninit(*this);
}


// --- src_lim.FGitfile.zd_include.EmptyQ
// Return true if index is empty
inline bool src_lim::zd_include_EmptyQ(src_lim::FGitfile& gitfile) {
    return gitfile.zd_include_head == NULL;
}

// --- src_lim.FGitfile.zd_include.First
// If index empty, return NULL. Otherwise return pointer to first element in index
inline src_lim::FInclude* src_lim::zd_include_First(src_lim::FGitfile& gitfile) {
    src_lim::FInclude *row = NULL;
    row = gitfile.zd_include_head;
    return row;
}

// --- src_lim.FGitfile.zd_include.InLlistQ
// Return true if row is in the linked list, false otherwise
inline bool src_lim::zd_include_InLlistQ(src_lim::FInclude& row) {
    bool result = false;
    result = !(row.zd_include_next == (src_lim::FInclude*)-1);
    return result;
}

// --- src_lim.FGitfile.zd_include.Last
// If index empty, return NULL. Otherwise return pointer to last element in index
inline src_lim::FInclude* src_lim::zd_include_Last(src_lim::FGitfile& gitfile) {
    src_lim::FInclude *row = NULL;
    row = gitfile.zd_include_tail;
    return row;
}

// --- src_lim.FGitfile.zd_include.N
// Return number of items in the linked list
inline i32 src_lim::zd_include_N(const src_lim::FGitfile& gitfile) {
    return gitfile.zd_include_n;
}

// --- src_lim.FGitfile.zd_include.Next
// Return pointer to next element in the list
inline src_lim::FInclude* src_lim::zd_include_Next(src_lim::FInclude &row) {
    return row.zd_include_next;
}

// --- src_lim.FGitfile.zd_include.Prev
// Return pointer to previous element in the list
inline src_lim::FInclude* src_lim::zd_include_Prev(src_lim::FInclude &row) {
    return row.zd_include_prev;
}

// --- src_lim.FGitfile.zd_include.qLast
// Return reference to last element in the index. No bounds checking.
inline src_lim::FInclude& src_lim::zd_include_qLast(src_lim::FGitfile& gitfile) {
    src_lim::FInclude *row = NULL;
    row = gitfile.zd_include_tail;
    return *row;
}

// --- src_lim.FGitfile.c_linelim.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool src_lim::c_linelim_InsertMaybe(src_lim::FGitfile& gitfile, src_lim::FLinelim& row) {
    src_lim::FLinelim* ptr = gitfile.c_linelim;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        gitfile.c_linelim = &row;
    }
    return retval;
}

// --- src_lim.FGitfile.c_linelim.Remove
// Remove element from index. If element is not in index, do nothing.
inline void src_lim::c_linelim_Remove(src_lim::FGitfile& gitfile, src_lim::FLinelim& row) {
    src_lim::FLinelim *ptr = gitfile.c_linelim;
    if (LIKELY(ptr == &row)) {
        gitfile.c_linelim = NULL;
    }
}

// --- src_lim.FGitfile.c_targsrc.InsertMaybe
// Insert row into pointer index. Return final membership status.
inline bool src_lim::c_targsrc_InsertMaybe(src_lim::FGitfile& gitfile, src_lim::FTargsrc& row) {
    src_lim::FTargsrc* ptr = gitfile.c_targsrc;
    bool retval = (ptr == NULL) | (ptr == &row);
    if (retval) {
        gitfile.c_targsrc = &row;
    }
    return retval;
}

// --- src_lim.FGitfile.c_targsrc.Remove
// Remove element from index. If element is not in index, do nothing.
inline void src_lim::c_targsrc_Remove(src_lim::FGitfile& gitfile, src_lim::FTargsrc& row) {
    src_lim::FTargsrc *ptr = gitfile.c_targsrc;
    if (LIKELY(ptr == &row)) {
        gitfile.c_targsrc = NULL;
    }
}

// --- src_lim.FGitfile..Init
// Set all fields to initial values.
inline void src_lim::FGitfile_Init(src_lim::FGitfile& gitfile) {
    gitfile.zd_include_head = NULL; // (src_lim.FGitfile.zd_include)
    gitfile.zd_include_n = 0; // (src_lim.FGitfile.zd_include)
    gitfile.zd_include_tail = NULL; // (src_lim.FGitfile.zd_include)
    gitfile.c_linelim = NULL;
    gitfile.c_targsrc = NULL;
    gitfile.ind_gitfile_next = (src_lim::FGitfile*)-1; // (src_lim.FDb.ind_gitfile) not-in-hash
}

// --- src_lim.FGitfile.zd_include_curs.Reset
// cursor points to valid item
inline void src_lim::gitfile_zd_include_curs_Reset(gitfile_zd_include_curs &curs, src_lim::FGitfile &parent) {
    curs.row = parent.zd_include_head;
}

// --- src_lim.FGitfile.zd_include_curs.ValidQ
// cursor points to valid item
inline bool src_lim::gitfile_zd_include_curs_ValidQ(gitfile_zd_include_curs &curs) {
    return curs.row != NULL;
}

// --- src_lim.FGitfile.zd_include_curs.Next
// proceed to next item
inline void src_lim::gitfile_zd_include_curs_Next(gitfile_zd_include_curs &curs) {
    curs.row = (*curs.row).zd_include_next;
}

// --- src_lim.FGitfile.zd_include_curs.Access
// item access
inline src_lim::FInclude& src_lim::gitfile_zd_include_curs_Access(gitfile_zd_include_curs &curs) {
    return *curs.row;
}
inline src_lim::FInclude::FInclude() {
    src_lim::FInclude_Init(*this);
}

inline src_lim::FInclude::~FInclude() {
    src_lim::FInclude_Uninit(*this);
}


// --- src_lim.FInclude..Init
// Set all fields to initial values.
inline void src_lim::FInclude_Init(src_lim::FInclude& include) {
    include.sys = bool(false);
    include.zd_include_next = (src_lim::FInclude*)-1; // (src_lim.FGitfile.zd_include) not-in-list
    include.zd_include_prev = NULL; // (src_lim.FGitfile.zd_include)
}
inline src_lim::FLinelim::FLinelim() {
    src_lim::FLinelim_Init(*this);
}

inline src_lim::FLinelim::~FLinelim() {
    src_lim::FLinelim_Uninit(*this);
}


// --- src_lim.FLinelim..Init
// Set all fields to initial values.
inline void src_lim::FLinelim_Init(src_lim::FLinelim& linelim) {
    linelim.nlongline = u32(0);
    linelim.longestline = u32(0);
    linelim.nbadws = u32(0);
    linelim.maxws = u32(0);
    linelim.nlongfunc = u32(0);
    linelim.longestfunc = u32(0);
    linelim.nmysteryfunc = u32(0);
}
inline src_lim::FTargsrc::FTargsrc() {
    src_lim::FTargsrc_Init(*this);
}

inline src_lim::FTargsrc::~FTargsrc() {
    src_lim::FTargsrc_Uninit(*this);
}


// --- src_lim.FTargsrc..Init
// Set all fields to initial values.
inline void src_lim::FTargsrc_Init(src_lim::FTargsrc& targsrc) {
    targsrc.p_gitfile = NULL;
    targsrc.select = bool(false);
}
inline src_lim::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline src_lim::FieldId::FieldId(src_lim_FieldIdEnum arg) { this->value = i32(arg); }
inline src_lim::FieldId::FieldId() {
    src_lim::FieldId_Init(*this);
}


// --- src_lim.FieldId.value.GetEnum
// Get value of field as enum type
inline src_lim_FieldIdEnum src_lim::value_GetEnum(const src_lim::FieldId& parent) {
    return src_lim_FieldIdEnum(parent.value);
}

// --- src_lim.FieldId.value.SetEnum
// Set value of field from enum type.
inline void src_lim::value_SetEnum(src_lim::FieldId& parent, src_lim_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- src_lim.FieldId.value.Cast
inline src_lim::FieldId::operator src_lim_FieldIdEnum () const {
    return src_lim_FieldIdEnum((*this).value);
}

// --- src_lim.FieldId..Init
// Set all fields to initial values.
inline void src_lim::FieldId_Init(src_lim::FieldId& parent) {
    parent.value = i32(-1);
}
inline src_lim::TableId::TableId(i32                            in_value)
    : value(in_value)
{
}
inline src_lim::TableId::TableId(src_lim_TableIdEnum arg) { this->value = i32(arg); }
inline src_lim::TableId::TableId() {
    src_lim::TableId_Init(*this);
}


// --- src_lim.TableId.value.GetEnum
// Get value of field as enum type
inline src_lim_TableIdEnum src_lim::value_GetEnum(const src_lim::TableId& parent) {
    return src_lim_TableIdEnum(parent.value);
}

// --- src_lim.TableId.value.SetEnum
// Set value of field from enum type.
inline void src_lim::value_SetEnum(src_lim::TableId& parent, src_lim_TableIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- src_lim.TableId.value.Cast
inline src_lim::TableId::operator src_lim_TableIdEnum () const {
    return src_lim_TableIdEnum((*this).value);
}

// --- src_lim.TableId..Init
// Set all fields to initial values.
inline void src_lim::TableId_Init(src_lim::TableId& parent) {
    parent.value = i32(-1);
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const src_lim::trace &row) {// cfmt:src_lim.trace.String
    src_lim::trace_Print(const_cast<src_lim::trace&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const src_lim::FieldId &row) {// cfmt:src_lim.FieldId.String
    src_lim::FieldId_Print(const_cast<src_lim::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const src_lim::TableId &row) {// cfmt:src_lim.TableId.String
    src_lim::TableId_Print(const_cast<src_lim::TableId&>(row), str);
    return str;
}
