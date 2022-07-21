#pragma once

/* ---------- macros */

#define DATUM_INDEX_TO_ABSOLUTE_INDEX(DATUM_INDEX) (unsigned short)((DATUM_INDEX) & 0xFFFF)
#define DATUM_INDEX_TO_IDENTIFIER(DATUM_INDEX) (unsigned short)(((DATUM_INDEX) >> 16) & 0xFFFF)
#define BUILD_DATUM_INDEX(IDENTIFIER, ABSOLUTE_INDEX) (((ABSOLUTE_INDEX) & 0xFFFF) | ((IDENTIFIER) << 16))

/* ---------- classes */

class c_datum_handle final
{
private:
	int m_value;

public:
	c_datum_handle();
	c_datum_handle(const int m_value);
	c_datum_handle(unsigned short const identifer, unsigned short const absolute_index);
	c_datum_handle(c_datum_handle const &other);

	int get_value() const;
	unsigned short get_identifier() const;
	unsigned short get_absolute_index() const;

	bool valid() const;

	bool operator==(c_datum_handle const &other) const;
	bool operator!=(c_datum_handle const &other) const;

	explicit operator long() const;
};
