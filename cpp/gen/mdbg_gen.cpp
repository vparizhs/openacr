//
// cpp/gen/mdbg_gen.cpp
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#include "include/algo.h"  // hard-coded include
#include "include/gen/mdbg_gen.h"
#include "include/gen/mdbg_gen.inl.h"
#include "include/gen/dev_gen.h"
#include "include/gen/dev_gen.inl.h"
#include "include/gen/algo_gen.h"
#include "include/gen/algo_gen.inl.h"
#include "include/gen/command_gen.h"
#include "include/gen/command_gen.inl.h"
#include "include/gen/lib_json_gen.h"
#include "include/gen/lib_json_gen.inl.h"
#include "include/gen/lib_prot_gen.h"
#include "include/gen/lib_prot_gen.inl.h"
#include "include/gen/algo_lib_gen.h"
#include "include/gen/algo_lib_gen.inl.h"
//#pragma endinclude

// Instantiate all libraries linked into this executable,
// in dependency order
lib_json::FDb   lib_json::_db;    // dependency found via dev.targdep
algo_lib::FDb   algo_lib::_db;    // dependency found via dev.targdep
mdbg::FDb       mdbg::_db;        // dependency found via dev.targdep

namespace mdbg {
const char *mdbg_help =
"mdbg: My debugger\n"
"Usage: mdbg [options]\n"
"    [target]       string  Executable name\n"
"    [args]         string  Additional module args\n"
"    -cfg           string  Configuration to use. default: \"debug\"\n"
"    -manywin               gdb-many-windows. default: false\n"
"    -disas                 Show disassembly (use F12). default: false\n"
"    -root                  Debug as root. default: false\n"
"    -attach                Attach to a running process. default: false\n"
"    -b             string  List of breakpoints, e.g. 'a.cpp:123 if cond1, func2'. default: \"main\"\n"
"    -catchthrow            Stop on exceptions. default: true\n"
"    -tui                   Use gdb -tui as the debugger. default: false\n"
"    -bcmd          string  Evaluate command at breakpoint\n"
"    -emacs                 Use emacs environment as the debugger. default: true\n"
"    -follow_child          . default: false\n"
"    -py                    Enable python scripting. default: false\n"
"    -in            string  Input directory or filename, - for stdin. default: \"data\"\n"
"    -verbose               Enable verbose mode\n"
"    -debug                 Enable debug mode\n"
"    -version               Show version information\n"
"    -sig                   Print SHA1 signatures for dispatches\n"
"    -help                  Print this screen and exit\n"
;


const char *mdbg_syntax =
"[target]:string=\n"
" [args]:string=\n"
" -cfg:string=\"debug\"\n"
" -manywin:flag\n"
" -disas:flag\n"
" -root:flag\n"
" -attach:flag\n"
" -b:string=\"main\"\n"
" -catchthrow:flag=true\n"
" -tui:flag\n"
" -bcmd:string=\n"
" -emacs:flag=true\n"
" -follow_child:flag\n"
" -py:flag\n"
" -in:string=\"data\"\n"
;
} // namespace mdbg
namespace mdbg {
    // Load statically available data into tables, register tables and database.
    static void          InitReflection();
    static bool          cfg_InputMaybe(dev::Cfg &elem) __attribute__((nothrow));
    static bool          builddir_InputMaybe(dev::Builddir &elem) __attribute__((nothrow));
    // find trace by row id (used to implement reflection)
    static algo::ImrowPtr trace_RowidFind(int t) __attribute__((nothrow));
    // Function return 1
    static i32           trace_N() __attribute__((__warn_unused_result__, nothrow, pure));
    static void          SizeCheck();
} // end namespace mdbg

// --- mdbg.FBuilddir.base.CopyOut
// Copy fields out of row
void mdbg::builddir_CopyOut(mdbg::FBuilddir &row, dev::Builddir &out) {
    out.builddir = row.builddir;
    out.comment = row.comment;
}

// --- mdbg.FBuilddir.base.CopyIn
// Copy fields in to row
void mdbg::builddir_CopyIn(mdbg::FBuilddir &row, dev::Builddir &in) {
    row.builddir = in.builddir;
    row.comment = in.comment;
}

// --- mdbg.FBuilddir.uname.Get
algo::Smallstr50 mdbg::uname_Get(mdbg::FBuilddir& builddir) {
    algo::Smallstr50 ret(algo::Pathcomp(builddir.builddir, ".LL-LL"));
    return ret;
}

// --- mdbg.FBuilddir.compiler.Get
algo::Smallstr50 mdbg::compiler_Get(mdbg::FBuilddir& builddir) {
    algo::Smallstr50 ret(algo::Pathcomp(builddir.builddir, ".LL-LR"));
    return ret;
}

// --- mdbg.FBuilddir.cfg.Get
algo::Smallstr50 mdbg::cfg_Get(mdbg::FBuilddir& builddir) {
    algo::Smallstr50 ret(algo::Pathcomp(builddir.builddir, ".LR-LL"));
    return ret;
}

// --- mdbg.FBuilddir.arch.Get
algo::Smallstr50 mdbg::arch_Get(mdbg::FBuilddir& builddir) {
    algo::Smallstr50 ret(algo::Pathcomp(builddir.builddir, ".LR-LR"));
    return ret;
}

// --- mdbg.FBuilddir..Uninit
void mdbg::FBuilddir_Uninit(mdbg::FBuilddir& builddir) {
    mdbg::FBuilddir &row = builddir; (void)row;
    mdbg::FCfg* p_cfg = mdbg::ind_cfg_Find(cfg_Get(row));
    if (p_cfg)  {
        c_builddir_Remove(*p_cfg, row);// remove builddir from index c_builddir
    }
}

// --- mdbg.FCfg.base.CopyOut
// Copy fields out of row
void mdbg::cfg_CopyOut(mdbg::FCfg &row, dev::Cfg &out) {
    out.cfg = row.cfg;
    out.suffix = row.suffix;
    out.comment = row.comment;
}

// --- mdbg.FCfg.base.CopyIn
// Copy fields in to row
void mdbg::cfg_CopyIn(mdbg::FCfg &row, dev::Cfg &in) {
    row.cfg = in.cfg;
    row.suffix = in.suffix;
    row.comment = in.comment;
}

// --- mdbg.FCfg.c_builddir.Insert
// Insert pointer to row into array. Row must not already be in array.
// If pointer is already in the array, it may be inserted twice.
void mdbg::c_builddir_Insert(mdbg::FCfg& cfg, mdbg::FBuilddir& row) {
    if (bool_Update(row.cfg_c_builddir_in_ary,true)) {
        // reserve space
        c_builddir_Reserve(cfg, 1);
        u32 n  = cfg.c_builddir_n;
        u32 at = n;
        mdbg::FBuilddir* *elems = cfg.c_builddir_elems;
        elems[at] = &row;
        cfg.c_builddir_n = n+1;

    }
}

// --- mdbg.FCfg.c_builddir.InsertMaybe
// Insert pointer to row in array.
// If row is already in the array, do nothing.
// Return value: whether element was inserted into array.
bool mdbg::c_builddir_InsertMaybe(mdbg::FCfg& cfg, mdbg::FBuilddir& row) {
    bool retval = !row.cfg_c_builddir_in_ary;
    c_builddir_Insert(cfg,row); // check is performed in _Insert again
    return retval;
}

// --- mdbg.FCfg.c_builddir.Remove
// Find element using linear scan. If element is in array, remove, otherwise do nothing
void mdbg::c_builddir_Remove(mdbg::FCfg& cfg, mdbg::FBuilddir& row) {
    if (bool_Update(row.cfg_c_builddir_in_ary,false)) {
        int lim = cfg.c_builddir_n;
        mdbg::FBuilddir* *elems = cfg.c_builddir_elems;
        // search backward, so that most recently added element is found first.
        // if found, shift array.
        for (int i = lim-1; i>=0; i--) {
            mdbg::FBuilddir* elem = elems[i]; // fetch element
            if (elem == &row) {
                int j = i + 1;
                size_t nbytes = sizeof(mdbg::FBuilddir*) * (lim - j);
                memmove(elems + i, elems + j, nbytes);
                cfg.c_builddir_n = lim - 1;
                break;
            }
        }
    }
}

// --- mdbg.FCfg.c_builddir.Reserve
// Reserve space in index for N more elements;
void mdbg::c_builddir_Reserve(mdbg::FCfg& cfg, u32 n) {
    u32 old_max = cfg.c_builddir_max;
    if (UNLIKELY(cfg.c_builddir_n + n > old_max)) {
        u32 new_max  = u32_Max(4, old_max * 2);
        u32 old_size = old_max * sizeof(mdbg::FBuilddir*);
        u32 new_size = new_max * sizeof(mdbg::FBuilddir*);
        void *new_mem = mdbg::lpool_ReallocMem(cfg.c_builddir_elems, old_size, new_size);
        if (UNLIKELY(!new_mem)) {
            FatalErrorExit("mdbg.out_of_memory  field:mdbg.FCfg.c_builddir");
        }
        cfg.c_builddir_elems = (mdbg::FBuilddir**)new_mem;
        cfg.c_builddir_max = new_max;
    }
}

// --- mdbg.FCfg..Uninit
void mdbg::FCfg_Uninit(mdbg::FCfg& cfg) {
    mdbg::FCfg &row = cfg; (void)row;
    ind_cfg_Remove(row); // remove cfg from index ind_cfg

    // mdbg.FCfg.c_builddir.Uninit (Ptrary)  //
    mdbg::lpool_FreeMem(cfg.c_builddir_elems, sizeof(mdbg::FBuilddir*)*cfg.c_builddir_max); // (mdbg.FCfg.c_builddir)
}

// --- mdbg.trace..Print
// print string representation of mdbg::trace to string LHS, no header -- cprint:mdbg.trace.String
void mdbg::trace_Print(mdbg::trace & row, algo::cstring &str) {
    algo::tempstr temp;
    str << "mdbg.trace";
    (void)row;//only to avoid -Wunused-parameter
}

// --- mdbg.FDb.lpool.FreeMem
// Free block of memory previously returned by Lpool.
void mdbg::lpool_FreeMem(void *mem, u64 size) {
    if (mem) {
        size = u64_Max(size,16); // enforce alignment
        u64 cell = algo::u64_BitScanReverse(size-1) + 1;
        lpool_Lpblock *temp = (lpool_Lpblock*)mem; // push  singly linked list
        temp->next = _db.lpool_free[cell];
        _db.lpool_free[cell] = temp;
    }
}

// --- mdbg.FDb.lpool.AllocMem
// Allocate new piece of memory at least SIZE bytes long.
// If not successful, return NULL
// The allocated block is 16-byte aligned
void* mdbg::lpool_AllocMem(u64 size) {
    size     = u64_Max(size,16); // enforce alignment
    u64 cell = algo::u64_BitScanReverse(size-1)+1;
    u64 i    = cell;
    u8 *retval = NULL;
    // try to find a block that's at least as large as required.
    // if found, remove from free list
    for (; i < 31; i++) {
        lpool_Lpblock *blk = _db.lpool_free[i];
        if (blk) {
            _db.lpool_free[i] = blk->next;
            retval = (u8*)blk;
            break;
        }
    }
    // if suitable size block is not found, create a new one
    // by requesting a block from the base allocator.
    if (UNLIKELY(!retval)) {
        i = u64_Max(cell, 21); // 2MB min -- allow huge page to be used
        retval = (u8*)algo_lib::sbrk_AllocMem(1<<i);
    }
    if (LIKELY(retval)) {
        // if block is more than 2x as large as needed, return the upper half to the free
        // list (repeatedly). meanwhile, retval doesn't change.
        while (i > cell) {
            i--;
            int half = 1<<i;
            lpool_Lpblock *blk = (lpool_Lpblock*)(retval + half);
            blk->next = _db.lpool_free[i];
            _db.lpool_free[i] = blk;
        }
    }
    return retval;
}

// --- mdbg.FDb.lpool.ReserveBuffers
// Add N buffers of some size to the free store
bool mdbg::lpool_ReserveBuffers(int nbuf, u64 bufsize) {
    bool retval = true;
    bufsize = u64_Max(bufsize, 16);
    for (int i = 0; i < nbuf; i++) {
        u64     cell = algo::u64_BitScanReverse(bufsize-1)+1;
        u64     size = 1ULL<<cell;
        lpool_Lpblock *temp = (lpool_Lpblock*)algo_lib::sbrk_AllocMem(size);
        if (temp == NULL) {
            retval = false;
            break;// why continue?
        } else {
            temp->next = _db.lpool_free[cell];
            _db.lpool_free[cell] = temp;
        }
    }
    return retval;
}

// --- mdbg.FDb.lpool.ReallocMem
// Allocate new block, copy old to new, delete old.
// New memory is always allocated (i.e. size reduction is not a no-op)
// If no memory, return NULL: old memory untouched
void* mdbg::lpool_ReallocMem(void *oldmem, u64 old_size, u64 new_size) {
    void* ret = oldmem;
    if (new_size != old_size) {
        ret = lpool_AllocMem(new_size);
        if (ret && oldmem) {
            memcpy(ret,oldmem,u64_Min(new_size,old_size));
            lpool_FreeMem(oldmem, old_size);
        }
    }
    return ret;
}

// --- mdbg.FDb._db.MainArgs
// Main function
void mdbg::MainArgs(int argc, char **argv) {
    Argtuple argtuple;
    Argtuple_ReadArgv(argtuple, argc,argv,mdbg_syntax, mdbg_help);
    vrfy(mdbg_ReadTupleMaybe(mdbg::_db.cmdline, argtuple.tuple),"where:read_cmdline");
    vrfy(mdbg::LoadTuplesMaybe(mdbg::_db.cmdline.in)
    ,tempstr()<<"where:load_input  "<<algo_lib::DetachBadTags());
    mdbg::Main(); // call through to user-defined main
}

// --- mdbg.FDb._db.MainLoop
// Main loop.
void mdbg::MainLoop() {
    algo::SchedTime time(algo::get_cycles());
    algo_lib::_db.clock          = time;
    do {
        algo_lib::_db.next_loop.value = algo_lib::_db.limit;
        algo_lib::Step(); // dependent namespace specified via (dev.targdep)
    } while (algo_lib::_db.next_loop < algo_lib::_db.limit);
}

// --- mdbg.FDb._db.Step
// Main step
void mdbg::Step() {
}

// --- mdbg.FDb._db.InitReflection
// Load statically available data into tables, register tables and database.
static void mdbg::InitReflection() {
    algo_lib::imdb_InsertMaybe(algo::Imdb("mdbg", mdbg::InsertStrptrMaybe, NULL, mdbg::MainLoop, NULL, algo::Comment()));

    algo::Imtable t_trace;
    t_trace.imtable         = "mdbg.trace";
    t_trace.ssimfile        = "";
    t_trace.size            = sizeof(mdbg::trace);
    t_trace.comment.value   = "";
    t_trace.c_RowidFind     = trace_RowidFind;
    t_trace.NItems          = trace_N;
    t_trace.Print           = (algo::ImrowPrintFcn)mdbg::trace_Print;
    algo_lib::imtable_InsertMaybe(t_trace);


    // -- load signatures of existing dispatches --
    algo_lib::InsertStrptrMaybe("dmmeta.Dispsigcheck  dispsig:'mdbg.Input'  signature:'a39a7508119d6dc51451d2cda9f120fd888b1184'");
}

// --- mdbg.FDb._db.StaticCheck
void mdbg::StaticCheck() {
    algo_assert(_offset_of(mdbg::FieldId, value) + sizeof(((mdbg::FieldId*)0)->value) == sizeof(mdbg::FieldId));
}

// --- mdbg.FDb._db.InsertStrptrMaybe
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool mdbg::InsertStrptrMaybe(algo::strptr str) {
    bool retval = true;
    mdbg::TableId table_id(-1);
    value_SetStrptrMaybe(table_id, algo::GetTypeTag(str));
    switch (value_GetEnum(table_id)) {
        case mdbg_TableId_dev_Cfg: { // finput:mdbg.FDb.cfg
            dev::Cfg elem;
            retval = dev::Cfg_ReadStrptrMaybe(elem, str);
            retval = retval && cfg_InputMaybe(elem);
            break;
        }
        case mdbg_TableId_dev_Builddir: { // finput:mdbg.FDb.builddir
            dev::Builddir elem;
            retval = dev::Builddir_ReadStrptrMaybe(elem, str);
            retval = retval && builddir_InputMaybe(elem);
            break;
        }
        default:
        retval = algo_lib::InsertStrptrMaybe(str);
        break;
    } //switch
    if (!retval) {
        algo_lib::NoteInsertErr(str); // increment error counter
    }
    return retval;
}

// --- mdbg.FDb._db.LoadTuplesMaybe
// Load all finputs from given directory.
bool mdbg::LoadTuplesMaybe(algo::strptr root) {
    bool retval = true;
    static const char *ssimfiles[] = {
        "dev.cfg", "dev.builddir"
        , NULL};
        retval = algo_lib::DoLoadTuples(root, mdbg::InsertStrptrMaybe, ssimfiles, true);
        return retval;
}

// --- mdbg.FDb._db.LoadSsimfileMaybe
// Load specified ssimfile.
bool mdbg::LoadSsimfileMaybe(algo::strptr fname) {
    bool retval = true;
    if (FileQ(fname)) {
        retval = algo_lib::LoadTuplesFile(fname, mdbg::InsertStrptrMaybe, true);
    }
    return retval;
}

// --- mdbg.FDb._db.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool mdbg::_db_XrefMaybe() {
    bool retval = true;
    return retval;
}

// --- mdbg.FDb.cfg.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
mdbg::FCfg& mdbg::cfg_Alloc() {
    mdbg::FCfg* row = cfg_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("mdbg.out_of_mem  field:mdbg.FDb.cfg  comment:'Alloc failed'");
    }
    return *row;
}

// --- mdbg.FDb.cfg.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
mdbg::FCfg* mdbg::cfg_AllocMaybe() {
    mdbg::FCfg *row = (mdbg::FCfg*)cfg_AllocMem();
    if (row) {
        new (row) mdbg::FCfg; // call constructor
    }
    return row;
}

// --- mdbg.FDb.cfg.InsertMaybe
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
mdbg::FCfg* mdbg::cfg_InsertMaybe(const dev::Cfg &value) {
    mdbg::FCfg *row = &cfg_Alloc(); // if out of memory, process dies. if input error, return NULL.
    cfg_CopyIn(*row,const_cast<dev::Cfg&>(value));
    bool ok = cfg_XrefMaybe(*row); // this may return false
    if (!ok) {
        cfg_RemoveLast(); // delete offending row, any existing xrefs are cleared
        row = NULL; // forget this ever happened
    }
    return row;
}

// --- mdbg.FDb.cfg.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* mdbg::cfg_AllocMem() {
    u64 new_nelems     = _db.cfg_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    mdbg::FCfg*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.cfg_lary[bsr];
        if (!lev) {
            lev=(mdbg::FCfg*)mdbg::lpool_AllocMem(sizeof(mdbg::FCfg) * (u64(1)<<bsr));
            _db.cfg_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.cfg_n = new_nelems;
        ret = lev + index;
    }
    return ret;
}

// --- mdbg.FDb.cfg.RemoveAll
// Remove all elements from Lary
void mdbg::cfg_RemoveAll() {
    for (u64 n = _db.cfg_n; n>0; ) {
        n--;
        cfg_qFind(u64(n)).~FCfg(); // destroy last element
        _db.cfg_n = n;
    }
}

// --- mdbg.FDb.cfg.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void mdbg::cfg_RemoveLast() {
    u64 n = _db.cfg_n;
    if (n > 0) {
        n -= 1;
        cfg_qFind(u64(n)).~FCfg();
        _db.cfg_n = n;
    }
}

// --- mdbg.FDb.cfg.InputMaybe
static bool mdbg::cfg_InputMaybe(dev::Cfg &elem) {
    bool retval = true;
    retval = cfg_InsertMaybe(elem);
    return retval;
}

// --- mdbg.FDb.cfg.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool mdbg::cfg_XrefMaybe(mdbg::FCfg &row) {
    bool retval = true;
    (void)row;
    // insert cfg into index ind_cfg
    if (true) { // user-defined insert condition
        bool success = ind_cfg_InsertMaybe(row);
        if (UNLIKELY(!success)) {
            ch_RemoveAll(algo_lib::_db.errtext);
            algo_lib::_db.errtext << "mdbg.duplicate_key  xref:mdbg.FDb.ind_cfg"; // check for duplicate key
            return false;
        }
    }
    return retval;
}

// --- mdbg.FDb.ind_cfg.Find
// Find row by key. Return NULL if not found.
mdbg::FCfg* mdbg::ind_cfg_Find(const algo::strptr& key) {
    u32 index = algo::Smallstr50_Hash(0, key) & (_db.ind_cfg_buckets_n - 1);
    mdbg::FCfg* *e = &_db.ind_cfg_buckets_elems[index];
    mdbg::FCfg* ret=NULL;
    do {
        ret       = *e;
        bool done = !ret || (*ret).cfg == key;
        if (done) break;
        e         = &ret->ind_cfg_next;
    } while (true);
    return ret;
}

// --- mdbg.FDb.ind_cfg.GetOrCreate
// Find row by key. If not found, create and x-reference a new row with with this key.
mdbg::FCfg& mdbg::ind_cfg_GetOrCreate(const algo::strptr& key) {
    mdbg::FCfg* ret = ind_cfg_Find(key);
    if (!ret) { //  if memory alloc fails, process dies; if insert fails, function returns NULL.
        ret         = &cfg_Alloc();
        (*ret).cfg = key;
        bool good = cfg_XrefMaybe(*ret);
        if (!good) {
            cfg_RemoveLast(); // delete offending row, any existing xrefs are cleared
            ret = NULL;
        }
    }
    return *ret;
}

// --- mdbg.FDb.ind_cfg.InsertMaybe
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool mdbg::ind_cfg_InsertMaybe(mdbg::FCfg& row) {
    ind_cfg_Reserve(1);
    bool retval = true; // if already in hash, InsertMaybe returns true
    if (LIKELY(row.ind_cfg_next == (mdbg::FCfg*)-1)) {// check if in hash already
        u32 index = algo::Smallstr50_Hash(0, row.cfg) & (_db.ind_cfg_buckets_n - 1);
        mdbg::FCfg* *prev = &_db.ind_cfg_buckets_elems[index];
        do {
            mdbg::FCfg* ret = *prev;
            if (!ret) { // exit condition 1: reached the end of the list
                break;
            }
            if ((*ret).cfg == row.cfg) { // exit condition 2: found matching key
                retval = false;
                break;
            }
            prev = &ret->ind_cfg_next;
        } while (true);
        if (retval) {
            row.ind_cfg_next = *prev;
            _db.ind_cfg_n++;
            *prev = &row;
        }
    }
    return retval;
}

// --- mdbg.FDb.ind_cfg.Remove
// Remove reference to element from hash index. If element is not in hash, do nothing
void mdbg::ind_cfg_Remove(mdbg::FCfg& row) {
    if (LIKELY(row.ind_cfg_next != (mdbg::FCfg*)-1)) {// check if in hash already
        u32 index = algo::Smallstr50_Hash(0, row.cfg) & (_db.ind_cfg_buckets_n - 1);
        mdbg::FCfg* *prev = &_db.ind_cfg_buckets_elems[index]; // addr of pointer to current element
        while (mdbg::FCfg *next = *prev) {                          // scan the collision chain for our element
            if (next == &row) {        // found it?
                *prev = next->ind_cfg_next; // unlink (singly linked list)
                _db.ind_cfg_n--;
                row.ind_cfg_next = (mdbg::FCfg*)-1;// not-in-hash
                break;
            }
            prev = &next->ind_cfg_next;
        }
    }
}

// --- mdbg.FDb.ind_cfg.Reserve
// Reserve enough room in the hash for N more elements. Return success code.
void mdbg::ind_cfg_Reserve(int n) {
    u32 old_nbuckets = _db.ind_cfg_buckets_n;
    u32 new_nelems   = _db.ind_cfg_n + n;
    // # of elements has to be roughly equal to the number of buckets
    if (new_nelems > old_nbuckets) {
        int new_nbuckets = i32_Max(algo::BumpToPow2(new_nelems), u32(4));
        u32 old_size = old_nbuckets * sizeof(mdbg::FCfg*);
        u32 new_size = new_nbuckets * sizeof(mdbg::FCfg*);
        // allocate new array. we don't use Realloc since copying is not needed and factor of 2 probably
        // means new memory will have to be allocated anyway
        mdbg::FCfg* *new_buckets = (mdbg::FCfg**)mdbg::lpool_AllocMem(new_size);
        if (UNLIKELY(!new_buckets)) {
            FatalErrorExit("mdbg.out_of_memory  field:mdbg.FDb.ind_cfg");
        }
        memset(new_buckets, 0, new_size); // clear pointers
        // rehash all entries
        for (int i = 0; i < _db.ind_cfg_buckets_n; i++) {
            mdbg::FCfg* elem = _db.ind_cfg_buckets_elems[i];
            while (elem) {
                mdbg::FCfg &row        = *elem;
                mdbg::FCfg* next       = row.ind_cfg_next;
                u32 index          = algo::Smallstr50_Hash(0, row.cfg) & (new_nbuckets-1);
                row.ind_cfg_next     = new_buckets[index];
                new_buckets[index] = &row;
                elem               = next;
            }
        }
        // free old array
        mdbg::lpool_FreeMem(_db.ind_cfg_buckets_elems, old_size);
        _db.ind_cfg_buckets_elems = new_buckets;
        _db.ind_cfg_buckets_n = new_nbuckets;
    }
}

// --- mdbg.FDb.builddir.Alloc
// Allocate memory for new default row.
// If out of memory, process is killed.
mdbg::FBuilddir& mdbg::builddir_Alloc() {
    mdbg::FBuilddir* row = builddir_AllocMaybe();
    if (UNLIKELY(row == NULL)) {
        FatalErrorExit("mdbg.out_of_mem  field:mdbg.FDb.builddir  comment:'Alloc failed'");
    }
    return *row;
}

// --- mdbg.FDb.builddir.AllocMaybe
// Allocate memory for new element. If out of memory, return NULL.
mdbg::FBuilddir* mdbg::builddir_AllocMaybe() {
    mdbg::FBuilddir *row = (mdbg::FBuilddir*)builddir_AllocMem();
    if (row) {
        new (row) mdbg::FBuilddir; // call constructor
    }
    return row;
}

// --- mdbg.FDb.builddir.InsertMaybe
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
mdbg::FBuilddir* mdbg::builddir_InsertMaybe(const dev::Builddir &value) {
    mdbg::FBuilddir *row = &builddir_Alloc(); // if out of memory, process dies. if input error, return NULL.
    builddir_CopyIn(*row,const_cast<dev::Builddir&>(value));
    bool ok = builddir_XrefMaybe(*row); // this may return false
    if (!ok) {
        builddir_RemoveLast(); // delete offending row, any existing xrefs are cleared
        row = NULL; // forget this ever happened
    }
    return row;
}

// --- mdbg.FDb.builddir.AllocMem
// Allocate space for one element. If no memory available, return NULL.
void* mdbg::builddir_AllocMem() {
    u64 new_nelems     = _db.builddir_n+1;
    // compute level and index on level
    u64 bsr   = algo::u64_BitScanReverse(new_nelems);
    u64 base  = u64(1)<<bsr;
    u64 index = new_nelems-base;
    void *ret = NULL;
    // if level doesn't exist yet, create it
    mdbg::FBuilddir*  lev   = NULL;
    if (bsr < 32) {
        lev = _db.builddir_lary[bsr];
        if (!lev) {
            lev=(mdbg::FBuilddir*)mdbg::lpool_AllocMem(sizeof(mdbg::FBuilddir) * (u64(1)<<bsr));
            _db.builddir_lary[bsr] = lev;
        }
    }
    // allocate element from this level
    if (lev) {
        _db.builddir_n = new_nelems;
        ret = lev + index;
    }
    return ret;
}

// --- mdbg.FDb.builddir.RemoveAll
// Remove all elements from Lary
void mdbg::builddir_RemoveAll() {
    for (u64 n = _db.builddir_n; n>0; ) {
        n--;
        builddir_qFind(u64(n)).~FBuilddir(); // destroy last element
        _db.builddir_n = n;
    }
}

// --- mdbg.FDb.builddir.RemoveLast
// Delete last element of array. Do nothing if array is empty.
void mdbg::builddir_RemoveLast() {
    u64 n = _db.builddir_n;
    if (n > 0) {
        n -= 1;
        builddir_qFind(u64(n)).~FBuilddir();
        _db.builddir_n = n;
    }
}

// --- mdbg.FDb.builddir.InputMaybe
static bool mdbg::builddir_InputMaybe(dev::Builddir &elem) {
    bool retval = true;
    retval = builddir_InsertMaybe(elem);
    return retval;
}

// --- mdbg.FDb.builddir.XrefMaybe
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Caller must Delete or Unref such row.
bool mdbg::builddir_XrefMaybe(mdbg::FBuilddir &row) {
    bool retval = true;
    (void)row;
    mdbg::FCfg* p_cfg = mdbg::ind_cfg_Find(cfg_Get(row));
    if (UNLIKELY(!p_cfg)) {
        algo_lib::ResetErrtext() << "mdbg.bad_xref  index:mdbg.FDb.ind_cfg" << Keyval("key", cfg_Get(row));
        return false;
    }
    // insert builddir into index c_builddir
    if (true) { // user-defined insert condition
        c_builddir_Insert(*p_cfg, row);
    }
    return retval;
}

// --- mdbg.FDb.trace.RowidFind
// find trace by row id (used to implement reflection)
static algo::ImrowPtr mdbg::trace_RowidFind(int t) {
    return algo::ImrowPtr(t==0 ? u64(&_db.trace) : u64(0));
}

// --- mdbg.FDb.trace.N
// Function return 1
inline static i32 mdbg::trace_N() {
    return 1;
}

// --- mdbg.FDb..Init
// Set all fields to initial values.
void mdbg::FDb_Init() {
    memset(_db.lpool_free, 0, sizeof(_db.lpool_free));
    // initialize LAry cfg (mdbg.FDb.cfg)
    _db.cfg_n = 0;
    memset(_db.cfg_lary, 0, sizeof(_db.cfg_lary)); // zero out all level pointers
    mdbg::FCfg* cfg_first = (mdbg::FCfg*)mdbg::lpool_AllocMem(sizeof(mdbg::FCfg) * (u64(1)<<4));
    if (!cfg_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.cfg_lary[i]  = cfg_first;
        cfg_first    += 1ULL<<i;
    }
    // initialize hash table for mdbg::FCfg;
    _db.ind_cfg_n             	= 0; // (mdbg.FDb.ind_cfg)
    _db.ind_cfg_buckets_n     	= 4; // (mdbg.FDb.ind_cfg)
    _db.ind_cfg_buckets_elems 	= (mdbg::FCfg**)mdbg::lpool_AllocMem(sizeof(mdbg::FCfg*)*_db.ind_cfg_buckets_n); // initial buckets (mdbg.FDb.ind_cfg)
    if (!_db.ind_cfg_buckets_elems) {
        FatalErrorExit("out of memory"); // (mdbg.FDb.ind_cfg)
    }
    memset(_db.ind_cfg_buckets_elems, 0, sizeof(mdbg::FCfg*)*_db.ind_cfg_buckets_n); // (mdbg.FDb.ind_cfg)
    // initialize LAry builddir (mdbg.FDb.builddir)
    _db.builddir_n = 0;
    memset(_db.builddir_lary, 0, sizeof(_db.builddir_lary)); // zero out all level pointers
    mdbg::FBuilddir* builddir_first = (mdbg::FBuilddir*)mdbg::lpool_AllocMem(sizeof(mdbg::FBuilddir) * (u64(1)<<4));
    if (!builddir_first) {
        FatalErrorExit("out of memory");
    }
    for (int i = 0; i < 4; i++) {
        _db.builddir_lary[i]  = builddir_first;
        builddir_first    += 1ULL<<i;
    }

    mdbg::InitReflection();
}

// --- mdbg.FDb..Uninit
void mdbg::FDb_Uninit() {
    mdbg::FDb &row = _db; (void)row;

    // mdbg.FDb.builddir.Uninit (Lary)  //
    // skip destruction in global scope

    // mdbg.FDb.ind_cfg.Uninit (Thash)  //
    // skip destruction of ind_cfg in global scope

    // mdbg.FDb.cfg.Uninit (Lary)  //
    // skip destruction in global scope
}

// --- mdbg.FieldId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* mdbg::value_ToCstr(const mdbg::FieldId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case mdbg_FieldId_value            : ret = "value";  break;
    }
    return ret;
}

// --- mdbg.FieldId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void mdbg::value_Print(const mdbg::FieldId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- mdbg.FieldId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool mdbg::value_SetStrptrMaybe(mdbg::FieldId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 5: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(rhs[4])<<32)) {
                case LE_STR5('v','a','l','u','e'): {
                    value_SetEnum(parent,mdbg_FieldId_value); ret = true; break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- mdbg.FieldId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void mdbg::value_SetStrptr(mdbg::FieldId& parent, algo::strptr rhs, mdbg_FieldIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- mdbg.FieldId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool mdbg::value_ReadStrptrMaybe(mdbg::FieldId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- mdbg.FieldId..ReadStrptrMaybe
// Read fields of mdbg::FieldId from an ascii string.
// The format of the string is the format of the mdbg::FieldId's only field
bool mdbg::FieldId_ReadStrptrMaybe(mdbg::FieldId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && mdbg::value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- mdbg.FieldId..Print
// print string representation of mdbg::FieldId to string LHS, no header -- cprint:mdbg.FieldId.String
void mdbg::FieldId_Print(mdbg::FieldId & row, algo::cstring &str) {
    mdbg::value_Print(row, str);
}

// --- mdbg.TableId.value.ToCstr
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char* mdbg::value_ToCstr(const mdbg::TableId& parent) {
    const char *ret = NULL;
    switch(value_GetEnum(parent)) {
        case mdbg_TableId_dev_Builddir     : ret = "dev.Builddir";  break;
        case mdbg_TableId_dev_Cfg          : ret = "dev.Cfg";  break;
    }
    return ret;
}

// --- mdbg.TableId.value.Print
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void mdbg::value_Print(const mdbg::TableId& parent, algo::cstring &lhs) {
    const char *strval = value_ToCstr(parent);
    if (strval) {
        lhs << strval;
    } else {
        lhs << parent.value;
    }
}

// --- mdbg.TableId.value.SetStrptrMaybe
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool mdbg::value_SetStrptrMaybe(mdbg::TableId& parent, algo::strptr rhs) {
    bool ret = false;
    switch (elems_N(rhs)) {
        case 7: {
            switch (u64(algo::ReadLE32(rhs.elems))|(u64(algo::ReadLE16(rhs.elems+4))<<32)|(u64(rhs[6])<<48)) {
                case LE_STR7('d','e','v','.','C','f','g'): {
                    value_SetEnum(parent,mdbg_TableId_dev_Cfg); ret = true; break;
                }
                case LE_STR7('d','e','v','.','c','f','g'): {
                    value_SetEnum(parent,mdbg_TableId_dev_cfg); ret = true; break;
                }
            }
            break;
        }
        case 12: {
            switch (algo::ReadLE64(rhs.elems)) {
                case LE_STR8('d','e','v','.','B','u','i','l'): {
                    if (memcmp(rhs.elems+8,"ddir",4)==0) { value_SetEnum(parent,mdbg_TableId_dev_Builddir); ret = true; break; }
                    break;
                }
                case LE_STR8('d','e','v','.','b','u','i','l'): {
                    if (memcmp(rhs.elems+8,"ddir",4)==0) { value_SetEnum(parent,mdbg_TableId_dev_builddir); ret = true; break; }
                    break;
                }
            }
            break;
        }
    }
    return ret;
}

// --- mdbg.TableId.value.SetStrptr
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void mdbg::value_SetStrptr(mdbg::TableId& parent, algo::strptr rhs, mdbg_TableIdEnum dflt) {
    if (!value_SetStrptrMaybe(parent,rhs)) value_SetEnum(parent,dflt);
}

// --- mdbg.TableId.value.ReadStrptrMaybe
// Convert string to field. Return success value
bool mdbg::value_ReadStrptrMaybe(mdbg::TableId& parent, algo::strptr rhs) {
    bool retval = false;
    retval = value_SetStrptrMaybe(parent,rhs); // try symbol conversion
    if (!retval) { // didn't work? try reading as underlying type
        retval = i32_ReadStrptrMaybe(parent.value,rhs);
    }
    return retval;
}

// --- mdbg.TableId..ReadStrptrMaybe
// Read fields of mdbg::TableId from an ascii string.
// The format of the string is the format of the mdbg::TableId's only field
bool mdbg::TableId_ReadStrptrMaybe(mdbg::TableId &parent, algo::strptr in_str) {
    bool retval = true;
    retval = retval && mdbg::value_ReadStrptrMaybe(parent, in_str);
    return retval;
}

// --- mdbg.TableId..Print
// print string representation of mdbg::TableId to string LHS, no header -- cprint:mdbg.TableId.String
void mdbg::TableId_Print(mdbg::TableId & row, algo::cstring &str) {
    mdbg::value_Print(row, str);
}

// --- mdbg...main
int main(int argc, char **argv) {
    try {
        lib_json::FDb_Init();
        algo_lib::FDb_Init();
        mdbg::FDb_Init();
        algo_lib::_db.argc = argc;
        algo_lib::_db.argv = argv;
        algo_lib::IohookInit();
        mdbg::MainArgs(algo_lib::_db.argc,algo_lib::_db.argv); // dmmeta.main:mdbg
    } catch(algo_lib::ErrorX &x) {
        prerr("mdbg.error  " << x); // there may be additional hints in DetachBadTags
        algo_lib::_db.exit_code = 1;
    }
    if (algo_lib::_db.last_signal) {
        algo_lib::_db.exit_code = 1;
    }
    try {
        mdbg::FDb_Uninit();
        algo_lib::FDb_Uninit();
        lib_json::FDb_Uninit();
    } catch(algo_lib::ErrorX &) {
        // don't print anything, might crash
        algo_lib::_db.exit_code = 1;
    }
    // only the lower 1 byte makes it to the outside world
    (void)i32_UpdateMin(algo_lib::_db.exit_code,255);
    return algo_lib::_db.exit_code;
}

// --- mdbg...SizeCheck
inline static void mdbg::SizeCheck() {
}
