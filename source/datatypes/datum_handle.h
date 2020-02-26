/*
DATUM_HANDLE.H
Monday, February 24, 2020 12:08:11 AM
*/

#pragma once

/* ---------- classes */

class c_datum_handle final
{
private:
    unsigned long m_value;

public:
    c_datum_handle();
    c_datum_handle(unsigned long value);
    c_datum_handle(unsigned short index, unsigned short identifier);
    c_datum_handle(const c_datum_handle &other);

    unsigned long get_value() const;
    unsigned short get_index() const;
    unsigned short get_identifier() const;

    operator unsigned long() const;
};
