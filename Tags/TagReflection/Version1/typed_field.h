#pragma once

template<typename t_field_type_>
class h_typed_field :
	public h_field
{
public:
	using t_field_type = t_field_type_;

#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
	BCS_SHARED explicit h_typed_field() = delete;
	BCS_SHARED explicit h_typed_field(h_typed_field const& field) = delete;
	BCS_SHARED explicit h_typed_field(t_field_type const& _value) = delete;
	BCS_SHARED explicit h_typed_field(t_field_type&& _value) = delete;
	BCS_SHARED virtual ~h_typed_field();
#else

	//BCS_SHARED explicit h_typed_field() : value() {}
	//BCS_SHARED explicit h_typed_field(h_typed_field const& field) : value(field.value) {}
	//BCS_SHARED explicit h_typed_field(t_field_type const& _value) : value(_value) {}
	//BCS_SHARED explicit h_typed_field(t_field_type&& _value) : value(_value) {}
	//BCS_SHARED virtual ~h_typed_field();

	BCS_SHARED explicit h_typed_field() = delete;
	BCS_SHARED explicit h_typed_field(h_prototype& parent);
	BCS_SHARED explicit h_typed_field(h_typed_field const& field) = delete;
	// BCS_SHARED explicit h_typed_field(t_field_type const& _value);
	BCS_SHARED virtual ~h_typed_field();
#endif

#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT

	virtual void const* get_data() const override;
	virtual void* get_data() override;
	virtual operator t_field_type const& () const;
	virtual operator t_field_type& ();
	virtual h_typed_field& operator=(t_field_type const& _value);
	virtual h_typed_field& operator=(t_field_type&& _value);
	virtual bool operator==(t_field_type const& _value);
	virtual bool operator==(t_field_type&& _value);
	virtual bool operator!=(t_field_type const& _value);
	virtual bool operator!=(t_field_type&& _value);
	virtual t_field_type const* operator->() const;
	virtual t_field_type* operator->();

#else

	virtual void const* get_data() const override
	{
		return &value;
	}

	virtual void* get_data() override
	{
		return &value;
	}

	virtual operator t_field_type const& () const
	{
		return value;
	}

	virtual operator t_field_type& ()
	{
		return value;
	}

	h_typed_field<t_field_type>& operator=(t_field_type const& _value)
	{
		value = _value;
		return *this;
	}

	h_typed_field<t_field_type>& operator=(t_field_type&& _value)
	{
		value = _value;
		return *this;
	}

	virtual bool operator==(t_field_type&& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value == _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) == 0;
		}
	}

	virtual bool operator==(t_field_type const& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value == _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) == 0;
		}
	}

	virtual bool operator!=(t_field_type&& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value != _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) != 0;
		}
	}

	virtual bool operator!=(t_field_type const& _value)
	{
		if constexpr (
			std::is_arithmetic_v<t_field_type> ||
			std::is_same_v<h_string_id_field, t_field_type> ||
			std::is_base_of_v<h_prototype, t_field_type>)
		{
			return value != _value;
		}
		else
		{
			return memcmp(&value, &_value, sizeof(value)) != 0;
		}
	}

	virtual t_field_type const* operator->() const
	{
		return &value;
	}

	virtual t_field_type* operator->()
	{
		return &value;
	}

#endif

#ifdef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
public:
#else
protected:
#endif
	t_field_type value;
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_type, typename t_parent_type, uint32_t _field_index>
using h_prototype_field = h_typed_field<t_type>;

template <typename t_enum, typename t_storage, t_enum maximum_value, typename t_parent_type, uint32_t _field_index>
using h_prototype_enum = h_typed_field<t_storage>;

template <typename t_enum, typename t_storage, const int k_number_of_bits, typename t_parent_type, uint32_t _field_index>
using h_prototype_flags = h_typed_field<t_storage>;

#else

template<typename t_field_type_, typename t_parent_type, uint32_t _field_index>
class h_prototype_field :
	public h_typed_field<t_field_type_>
{
public:
	using t_field_type = t_field_type_;
	using t_base = h_typed_field<t_field_type>;

	explicit h_prototype_field() = delete;
	explicit h_prototype_field(h_prototype_field const& field) = delete;
	~h_prototype_field()
	{

	}

	operator t_field_type const& () const
	{
		return t_base::value;
	}

	operator t_field_type& ()
	{
		return t_base::value;
	}

	h_prototype_field& operator=(t_field_type&& _value)
	{
		t_base::value = _value;
		return *this;
	}

	h_prototype_field& operator=(t_field_type const& _value)
	{
		t_base::value = _value;
		return *this;
	}

	bool operator==(t_field_type const& _value) const
	{
		return t_base::value == _value;
	}

	bool operator==(t_field_type&& _value) const
	{
		return t_base::value == _value;
	}
	bool operator!=(t_field_type const& _value) const
	{
		return t_base::value != _value;
	}

	bool operator!=(t_field_type&& _value) const
	{
		return t_base::value != _value;
	}

	t_field_type const* operator->() const
	{
		return &this->value;
	}

	t_field_type* operator->()
	{
		return &this->value;
	}

	template<typename t_parent_type, uint32_t _field_index>
	bool operator==(h_prototype_field<t_field_type, t_parent_type, _field_index>& field)
	{
		return operator==(field.operator t_field_type & ());
	}
};

template <typename t_enum, typename t_storage, t_enum maximum_value, typename t_parent_type, uint32_t _field_index>
class h_prototype_enum :
	public h_typed_field<c_enum<t_enum, t_storage, t_enum(0), maximum_value>>
{
public:
	using t_field_type = c_enum<t_enum, t_storage, t_enum(0), maximum_value>;
	using t_base = h_typed_field<t_field_type>;

	explicit h_prototype_enum() = delete;
	explicit h_prototype_enum(h_prototype_enum const& field) = delete;
	~h_prototype_enum()
	{

	}

	operator t_enum () const
	{
		return t_base::value;
	}

	operator t_field_type const& () const
	{
		return t_base::value;
	}

	operator t_field_type& ()
	{
		return t_base::value;
	}

	h_prototype_enum& operator=(t_field_type&& _value)
	{
		t_base::value = _value;
		return *this;
	}

	h_prototype_enum& operator=(t_field_type const& _value)
	{
		t_base::value = _value;
		return *this;
	}

	bool operator==(t_field_type const& _value) const
	{
		return t_base::value == _value;
	}

	bool operator==(t_field_type&& _value) const
	{
		return t_base::value == _value;
	}
	bool operator!=(t_field_type const& _value) const
	{
		return t_base::value != _value;
	}

	bool operator!=(t_field_type&& _value) const
	{
		return t_base::value != _value;
	}

	t_field_type const* operator->() const
	{
		return &this->value;
	}

	t_field_type* operator->()
	{
		return &this->value;
	}

	template<typename t_parent_type, uint32_t _field_index>
	bool operator==(h_prototype_enum<t_enum, t_storage, maximum_value, t_parent_type, _field_index>& field)
	{
		return operator==(field.operator t_field_type & ());
	}
};

template <typename t_enum, typename t_storage, const int k_number_of_bits, typename t_parent_type, uint32_t _field_index>
class h_prototype_flags :
	public h_typed_field<c_flags<t_enum, t_storage, k_number_of_bits>>
{
public:
	using t_field_type = c_flags<t_enum, t_storage, k_number_of_bits>;
	using t_flags = t_field_type;
	using t_flags_no_init = c_flags_no_init<t_enum, t_storage, k_number_of_bits>;
	using t_base = h_typed_field<t_field_type>;

	explicit h_prototype_flags() = delete;
	explicit h_prototype_flags(h_prototype_flags const& field) = delete;
	~h_prototype_flags()
	{

	}

	operator t_field_type const& () const
	{
		return t_base::value;
	}

	operator t_field_type& ()
	{
		return t_base::value;
	}

	h_prototype_flags& operator=(t_field_type&& _value)
	{
		t_base::value = _value;
		return *this;
	}

	h_prototype_flags& operator=(t_field_type const& _value)
	{
		t_base::value = _value;
		return *this;
	}

	bool operator==(t_field_type const& _value) const
	{
		return t_base::value == _value;
	}

	bool operator==(t_field_type&& _value) const
	{
		return t_base::value == _value;
	}
	bool operator!=(t_field_type const& _value) const
	{
		return t_base::value != _value;
	}

	bool operator!=(t_field_type&& _value) const
	{
		return t_base::value != _value;
	}

	t_field_type const* operator->() const
	{
		return &this->value;
	}

	t_field_type* operator->()
	{
		return &this->value;
	}

	template<typename t_parent_type, uint32_t _field_index>
	bool operator==(h_prototype_flags<t_enum, t_storage, k_number_of_bits, t_parent_type, _field_index>& field)
	{
		return operator==(field.operator t_field_type & ());
	}

	t_flags operator|(t_flags _value) const
	{
		return t_base::value.operator|(_value);
	}

	bool is_clear() const
	{
		return t_base::value.is_clear();
	}

	t_flags_no_init operator~() const
	{
		return t_base::value.operator~();
	}

	void clear()
	{
		t_base::value.clear();
	}

	bool test(t_enum bit) const
	{
		return t_base::value.test(bit);
	}

	void set(t_enum bit, bool _value)
	{
		t_base::value.set(bit, _value);
	}

	bool valid() const
	{
		return t_base::value.valid();
	}
};

#endif
