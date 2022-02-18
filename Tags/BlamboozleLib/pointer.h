#pragma once

template<typename t_underlying, bool bigendian>
struct t_pointer
{
	constexpr t_pointer() : raw_value() {}
	constexpr t_pointer(t_underlying _value) : raw_value(_value) {}
	constexpr explicit operator bool() const { return raw_value != 0; }
	constexpr bool operator ==(const t_underlying& _value) const { return raw_value == _value; }
	constexpr bool operator !=(const t_underlying& _value) const { return raw_value != _value; }
	constexpr bool operator ==(const t_pointer& _value) const { return raw_value == _value.raw_value; }
	constexpr bool operator !=(const t_pointer& _value) const { return raw_value != _value.raw_value; }
	constexpr bool operator <(const t_pointer& _value) const { return raw_value < _value.raw_value; }
	constexpr bool operator >(const t_pointer& _value) const { return raw_value > _value.raw_value; }
	constexpr bool operator <=(const t_pointer& _value) const { return raw_value <= _value.raw_value; }
	constexpr bool operator >=(const t_pointer& _value) const { return raw_value >= _value.raw_value; }
	constexpr bool operator ==(const int& _value) const { return raw_value == _value; }
	constexpr bool operator !=(const int& _value) const { return raw_value != _value; }
	constexpr t_underlying operator ~() const { return ~raw_value; }

	t_underlying value() const
	{
		if constexpr (bigendian && sizeof(t_underlying) == 4)
		{
			unsigned long byteswap_value = _byteswap_ulong(*reinterpret_cast<const unsigned long*>(&raw_value));
			return *reinterpret_cast<t_underlying*>(&byteswap_value);
		}
		else if constexpr (bigendian && sizeof(t_underlying) == 8)
		{
			unsigned long long byteswap_value = _byteswap_uint64(*reinterpret_cast<const unsigned long long*>(&raw_value));
			return *reinterpret_cast<t_underlying*>(&byteswap_value);
		}
		else
		{
			return raw_value;
		}
	}

	operator t_pointer<t_underlying, false>() const
	{
		return value();
	}

private:
	t_underlying raw_value;
};

template<typename t_underlying, bool bigendian>
void byteswap_inplace(t_pointer<t_underlying, bigendian>& value)
{
	byteswap_inplace(*reinterpret_cast<t_underlying*>(&value));
}

using ptr32 = t_pointer<unsigned long, false>;
using ptr64 = t_pointer<unsigned long long, false>;
using bptr32 = t_pointer<unsigned long, true>;
using bptr64 = t_pointer<unsigned long long, true>;

template<typename t_type = void*>
using typed_ptr32 = ptr32;

template<typename t_type = void*>
using typed_ptr64 = ptr64;

template<typename t_type = void*>
using typed_bptr32 = bptr32;

template<typename t_type = void*>
using typed_bptr64 = bptr64;
