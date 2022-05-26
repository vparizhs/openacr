//
// include/gen/ietf_gen.inl.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
//#pragma endinclude
inline ietf::FieldId::FieldId(i32                            in_value)
    : value(in_value)
{
}
inline ietf::FieldId::FieldId(ietf_FieldIdEnum arg) { this->value = i32(arg); }
inline ietf::FieldId::FieldId() {
    ietf::FieldId_Init(*this);
}


// --- ietf.FieldId.value.GetEnum
// Get value of field as enum type
inline ietf_FieldIdEnum ietf::value_GetEnum(const ietf::FieldId& parent) {
    return ietf_FieldIdEnum(parent.value);
}

// --- ietf.FieldId.value.SetEnum
// Set value of field from enum type.
inline void ietf::value_SetEnum(ietf::FieldId& parent, ietf_FieldIdEnum rhs) {
    parent.value = i32(rhs);
}

// --- ietf.FieldId.value.Cast
inline ietf::FieldId::operator ietf_FieldIdEnum () const {
    return ietf_FieldIdEnum((*this).value);
}

// --- ietf.FieldId..Init
// Set all fields to initial values.
inline void ietf::FieldId_Init(ietf::FieldId& parent) {
    parent.value = i32(-1);
}
inline ietf::Ipv4::Ipv4(u32                            in_ipv4)
    : ipv4(in_ipv4)
{
}

inline bool ietf::Ipv4::operator ==(const ietf::Ipv4 &rhs) const {
    return ietf::Ipv4_Eq(const_cast<ietf::Ipv4&>(*this),const_cast<ietf::Ipv4&>(rhs));
}

inline bool ietf::Ipv4::operator !=(const ietf::Ipv4 &rhs) const {
    return !ietf::Ipv4_Eq(const_cast<ietf::Ipv4&>(*this),const_cast<ietf::Ipv4&>(rhs));
}

inline bool ietf::Ipv4::operator <(const ietf::Ipv4 &rhs) const {
    return ietf::Ipv4_Lt(const_cast<ietf::Ipv4&>(*this),const_cast<ietf::Ipv4&>(rhs));
}
inline ietf::Ipv4::Ipv4() {
    ietf::Ipv4_Init(*this);
}


// --- ietf.Ipv4..Hash
inline u32 ietf::Ipv4_Hash(u32 prev, ietf::Ipv4 rhs) {
    prev = u32_Hash(prev, rhs.ipv4);
    return prev;
}

// --- ietf.Ipv4..Lt
inline bool ietf::Ipv4_Lt(ietf::Ipv4 lhs, ietf::Ipv4 rhs) {
    return u32_Lt(lhs.ipv4, rhs.ipv4);
}

// --- ietf.Ipv4..Cmp
inline i32 ietf::Ipv4_Cmp(ietf::Ipv4 lhs, ietf::Ipv4 rhs) {
    i32 retval = 0;
    retval = u32_Cmp(lhs.ipv4, rhs.ipv4);
    return retval;
}

// --- ietf.Ipv4..Init
// Set all fields to initial values.
inline void ietf::Ipv4_Init(ietf::Ipv4& parent) {
    parent.ipv4 = u32(0);
}

// --- ietf.Ipv4..Eq
inline bool ietf::Ipv4_Eq(ietf::Ipv4 lhs, ietf::Ipv4 rhs) {
    bool retval = true;
    retval = u32_Eq(lhs.ipv4, rhs.ipv4);
    return retval;
}

// --- ietf.Ipv4..Update
// Set value. Return true if new value is different from old value.
inline bool ietf::Ipv4_Update(ietf::Ipv4 &lhs, ietf::Ipv4 rhs) {
    bool ret = !Ipv4_Eq(lhs, rhs); // compare values
    if (ret) {
        lhs = rhs; // update
    }
    return ret;
}
inline ietf::Ipport::Ipport(ietf::Ipv4                     in_ip
        ,u16                            in_port)
    : ip(in_ip)
    , port(in_port)
{
}

inline bool ietf::Ipport::operator ==(const ietf::Ipport &rhs) const {
    return ietf::Ipport_Eq(const_cast<ietf::Ipport&>(*this),const_cast<ietf::Ipport&>(rhs));
}

inline bool ietf::Ipport::operator !=(const ietf::Ipport &rhs) const {
    return !ietf::Ipport_Eq(const_cast<ietf::Ipport&>(*this),const_cast<ietf::Ipport&>(rhs));
}

inline bool ietf::Ipport::operator <(const ietf::Ipport &rhs) const {
    return ietf::Ipport_Lt(const_cast<ietf::Ipport&>(*this),const_cast<ietf::Ipport&>(rhs));
}
inline ietf::Ipport::Ipport() {
    ietf::Ipport_Init(*this);
}


// --- ietf.Ipport..Hash
inline u32 ietf::Ipport_Hash(u32 prev, ietf::Ipport rhs) {
    prev = Ipv4_Hash(prev, rhs.ip);
    prev = u16_Hash(prev, rhs.port);
    return prev;
}

// --- ietf.Ipport..Lt
inline bool ietf::Ipport_Lt(ietf::Ipport lhs, ietf::Ipport rhs) {
    return Ipport_Cmp(lhs,rhs) < 0;
}

// --- ietf.Ipport..Cmp
inline i32 ietf::Ipport_Cmp(ietf::Ipport lhs, ietf::Ipport rhs) {
    i32 retval = 0;
    retval = ietf::Ipv4_Cmp(lhs.ip, rhs.ip);
    if (retval != 0) {
        return retval;
    }
    retval = u16_Cmp(lhs.port, rhs.port);
    return retval;
}

// --- ietf.Ipport..Init
// Set all fields to initial values.
inline void ietf::Ipport_Init(ietf::Ipport& parent) {
    parent.port = u16(0);
}

// --- ietf.Ipport..Eq
inline bool ietf::Ipport_Eq(ietf::Ipport lhs, ietf::Ipport rhs) {
    bool retval = true;
    retval = ietf::Ipv4_Eq(lhs.ip, rhs.ip);
    if (!retval) {
        return false;
    }
    retval = u16_Eq(lhs.port, rhs.port);
    return retval;
}

// --- ietf.Ipport..Update
// Set value. Return true if new value is different from old value.
inline bool ietf::Ipport_Update(ietf::Ipport &lhs, ietf::Ipport rhs) {
    bool ret = !Ipport_Eq(lhs, rhs); // compare values
    if (ret) {
        lhs = rhs; // update
    }
    return ret;
}
inline ietf::Ipv4Addr::Ipv4Addr(u32                            in_addr)
{
    addr_Set(*this,in_addr);
}

inline bool ietf::Ipv4Addr::operator ==(const ietf::Ipv4Addr &rhs) const {
    return ietf::Ipv4Addr_Eq(const_cast<ietf::Ipv4Addr&>(*this),const_cast<ietf::Ipv4Addr&>(rhs));
}

inline bool ietf::Ipv4Addr::operator !=(const ietf::Ipv4Addr &rhs) const {
    return !ietf::Ipv4Addr_Eq(const_cast<ietf::Ipv4Addr&>(*this),const_cast<ietf::Ipv4Addr&>(rhs));
}

inline bool ietf::Ipv4Addr::operator <(const ietf::Ipv4Addr &rhs) const {
    return ietf::Ipv4Addr_Lt(const_cast<ietf::Ipv4Addr&>(*this),const_cast<ietf::Ipv4Addr&>(rhs));
}
inline ietf::Ipv4Addr::Ipv4Addr() {
    ietf::Ipv4Addr_Init(*this);
}


// --- ietf.Ipv4Addr.addr.Get
inline u32 ietf::addr_Get(const ietf::Ipv4Addr& parent) {
    return be32toh(parent.addr_be); // read big-endian value from memory
}

// --- ietf.Ipv4Addr.addr.Set
inline void ietf::addr_Set(ietf::Ipv4Addr& parent, u32 rhs) {
    parent.addr_be = htobe32(rhs); // write big-endian value to memory
}

// --- ietf.Ipv4Addr..Hash
inline u32 ietf::Ipv4Addr_Hash(u32 prev, ietf::Ipv4Addr rhs) {
    prev = u32_Hash(prev, addr_Get(rhs));
    return prev;
}

// --- ietf.Ipv4Addr..Lt
inline bool ietf::Ipv4Addr_Lt(ietf::Ipv4Addr lhs, ietf::Ipv4Addr rhs) {
    return u32_Lt(addr_Get(lhs), addr_Get(rhs));
}

// --- ietf.Ipv4Addr..Cmp
inline i32 ietf::Ipv4Addr_Cmp(ietf::Ipv4Addr lhs, ietf::Ipv4Addr rhs) {
    i32 retval = 0;
    retval = u32_Cmp(addr_Get(lhs), addr_Get(rhs));
    return retval;
}

// --- ietf.Ipv4Addr..Init
// Set all fields to initial values.
inline void ietf::Ipv4Addr_Init(ietf::Ipv4Addr& parent) {
    parent.addr_be = htobe32(0); // write big-endian value to memory
}

// --- ietf.Ipv4Addr..Eq
inline bool ietf::Ipv4Addr_Eq(ietf::Ipv4Addr lhs, ietf::Ipv4Addr rhs) {
    bool retval = true;
    retval = u32_Eq(addr_Get(lhs), addr_Get(rhs));
    return retval;
}

// --- ietf.Ipv4Addr..Update
// Set value. Return true if new value is different from old value.
inline bool ietf::Ipv4Addr_Update(ietf::Ipv4Addr &lhs, ietf::Ipv4Addr rhs) {
    bool ret = !Ipv4Addr_Eq(lhs, rhs); // compare values
    if (ret) {
        lhs = rhs; // update
    }
    return ret;
}
inline ietf::Protocol::Protocol() {
}


inline algo::cstring &algo::operator <<(algo::cstring &str, const ietf::FieldId &row) {// cfmt:ietf.FieldId.String
    ietf::FieldId_Print(const_cast<ietf::FieldId&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const ietf::Ipv4 &row) {// cfmt:ietf.Ipv4.String
    ietf::Ipv4_Print(const_cast<ietf::Ipv4&>(row), str);
    return str;
}

inline algo::cstring &algo::operator <<(algo::cstring &str, const ietf::Ipport &row) {// cfmt:ietf.Ipport.String
    ietf::Ipport_Print(const_cast<ietf::Ipport&>(row), str);
    return str;
}
