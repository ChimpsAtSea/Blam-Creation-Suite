#include <blamlib/memory/data.h>

/* ---------- code */

c_datum_handle::c_datum_handle() :
	c_datum_handle(-1)
{
}

c_datum_handle::c_datum_handle(const long value) :
	m_value(value)
{
}

c_datum_handle::c_datum_handle(unsigned short const identifer, unsigned short const absolute_index) :
	c_datum_handle((long)(absolute_index | (identifer << 16)))
{
}

c_datum_handle::c_datum_handle(c_datum_handle const &other) :
	c_datum_handle(other.m_value)
{
}

long c_datum_handle::get_value() const
{
	return m_value;
}

unsigned short c_datum_handle::get_identifier() const
{
	return static_cast<unsigned short>(DATUM_INDEX_TO_IDENTIFIER(m_value));
}

unsigned short c_datum_handle::get_absolute_index() const
{
	return static_cast<unsigned short>(DATUM_INDEX_TO_ABSOLUTE_INDEX(m_value));
}

bool c_datum_handle::valid() const
{
	return m_value != -1;
}

bool c_datum_handle::operator==(c_datum_handle const &other) const
{
	return m_value == other.m_value;
}

bool c_datum_handle::operator!=(c_datum_handle const &other) const
{
	return !(*this == other);
}

c_datum_handle::operator long() const
{
	return m_value;
}
