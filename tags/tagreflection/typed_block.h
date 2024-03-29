#pragma once

template<typename h_custom_type>
class h_typed_block :
	public std::vector<h_custom_type>,
	public h_block
{
public:
	BCS_SHARED h_typed_block(h_type* parent = nullptr);

	BCS_SHARED virtual h_custom_type& operator[](uint32_t index) final;
	BCS_SHARED virtual const h_custom_type& operator[](uint32_t index) const final;
	BCS_SHARED virtual h_custom_type& get(uint32_t index) final;
	BCS_SHARED virtual const h_custom_type& get(uint32_t index) const final;
	BCS_SHARED virtual const h_custom_type* data() final;
	BCS_SHARED virtual uint32_t size() const final;
	BCS_SHARED virtual uint32_t data_size() const final;
	BCS_SHARED virtual h_custom_type& emplace_back() final;
	BCS_SHARED virtual h_custom_type& emplace_back(const h_prototype& value) final;
	BCS_SHARED virtual void reserve(uint32_t count) final;
	BCS_SHARED virtual void resize(uint32_t count) final;
	BCS_SHARED virtual void insert_hole(uint32_t index, uint32_t count) final;
	BCS_SHARED virtual void remove(uint32_t index) final;
	BCS_SHARED virtual void clear() final;
	BCS_SHARED virtual blofeld::s_tag_struct_definition const& get_tag_struct_definition() const final;

	//protected:
	//	h_typed_block(h_typed_block const&) = default;
};

#define _h_typed_block_ctor_impl(h_custom_type)																											\
template<>																																				\
h_typed_block<h_custom_type>::h_typed_block(h_type* parent) :																							\
	std::vector<h_custom_type>(),																														\
	h_block(parent)																																		\
{ }

#define _h_typed_block_get_tag_struct_definition_impl(h_custom_type)																					\
template<>																																				\
blofeld::s_tag_struct_definition const& h_typed_block<h_custom_type>::get_tag_struct_definition() const													\
{																																						\
	return h_custom_type::tag_struct_definition;																										\
}

#define _h_typed_block_array_operator_impl(h_custom_type)																								\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::operator[](uint32_t index)																			\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}																																						\
template<>																																				\
const h_custom_type& h_typed_block<h_custom_type>::operator[](uint32_t index) const																\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}																																						

#define _h_typed_block_get_impl(h_custom_type)																											\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::get(uint32_t index)																					\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}																																						\
template<>																																				\
const h_custom_type& h_typed_block<h_custom_type>::get(uint32_t index) const																		\
{																																						\
	return std::vector<h_custom_type>::operator [](index);																								\
}

#define _h_typed_block_data_impl(h_custom_type)																											\
template<>																																				\
const h_custom_type* h_typed_block<h_custom_type>::data()																								\
{																																						\
	auto values = std::vector<h_custom_type>::data();																									\
	return values;																																		\
}																																						

#define _h_typed_block_size_impl(h_custom_type)																											\
template<>																																				\
uint32_t h_typed_block<h_custom_type>::size()  const																								\
{																																						\
	return static_cast<unsigned long>(std::vector<h_custom_type>::size());																				\
}																																						

#define _h_typed_block_data_size_impl(h_custom_type)																									\
template<>																																				\
uint32_t h_typed_block<h_custom_type>::data_size() const																							\
{																																						\
	return static_cast<unsigned long>(std::vector<h_custom_type>::size() * sizeof(h_custom_type));														\
}																																						

#define _h_typed_block_emplace_back_impl(h_custom_type)																									\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::emplace_back()																								\
{																																						\
	return std::vector<h_custom_type>::emplace_back(this);																								\
}																																						

#define _h_typed_block_emplace_back_alt_impl(h_custom_type)																								\
template<>																																				\
h_custom_type& h_typed_block<h_custom_type>::emplace_back(const h_prototype& value)																		\
{																																						\
	const h_custom_type* typed_value = dynamic_cast<const h_custom_type*>(&value);																		\
	DEBUG_ASSERT(typed_value != nullptr);																												\
	h_custom_type& created_type = std::vector<h_custom_type>::emplace_back(this);																		\
	created_type = *typed_value;																														\
	return created_type;																																\
}

#define _h_typed_block_reserve_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::reserve(uint32_t count)																							\
{																																						\
	std::vector<h_custom_type>::reserve(count);																											\
}																																						

#define _h_typed_block_resize_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::resize(uint32_t count)																							\
{																																						\
	uint32_t old_count = static_cast<unsigned long>(std::vector<h_custom_type>::size());															\
	std::vector<h_custom_type>::resize(count);																											\
																																						\
	{																																					\
		/* fixup parents */																																\
		/* #TODO: is there a better way to do this?  */																									\
																																						\
		h_custom_type* raw_types = std::vector<h_custom_type>::data();																					\
		for (uint32_t index = old_count; index < count; index++) 																					\
		{																																				\
			raw_types[index]._set_parent(this);																											\
		}																																				\
	}																																					\
}																																						
																																						
#define _h_typed_block_insert_hole_impl(h_custom_type)																									\
template<>																																				\
void h_typed_block<h_custom_type>::insert_hole(uint32_t index, uint32_t count)																\
{																																						\
	std::vector<h_custom_type>::insert(std::vector<h_custom_type>::begin() + index, count, h_custom_type(this));										\
}																																						

#define _h_typed_block_remove_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::remove(uint32_t index)																							\
{																																						\
	std::vector<h_custom_type>::erase(std::vector<h_custom_type>::begin() + index);																		\
}																																						

#define _h_typed_block_clear_impl(h_custom_type)																										\
template<>																																				\
void h_typed_block<h_custom_type>::clear()																												\
{																																						\
	std::vector<h_custom_type>::clear();																												\
}

