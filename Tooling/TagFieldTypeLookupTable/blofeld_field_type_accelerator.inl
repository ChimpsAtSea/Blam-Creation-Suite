
using namespace blofeld;

c_blofeld_field_type_accelerator::c_blofeld_field_type_accelerator() :
    field_type_by_index(),
    hash_by_field_type()
{
    for (unsigned char& field_type : field_type_by_index)
    {
        field_type = k_number_of_blofeld_field_types;
    }

    BCS_RESULT rs = BCS_S_OK;
    for (uint32_t field_index = 0; field_index < blofeld::k_number_of_blofeld_field_types; field_index++)
    {
        blofeld::e_field field_type = static_cast<blofeld::e_field>(field_index);
        const char* tag_field_type;
        if (BCS_FAILED(rs = blofeld::field_to_tagfile_field_type(field_type, tag_field_type)))
        {
            BCS_FAIL_THROW(rs);
        }

        blofeld_field_type_accelerator_hash(hash, tag_field_type, k_accelerator_seed);
        uint32_t index = hash & k_accelerator_bit_mask;

        ASSERT(index < _countof(field_type_by_index));

        field_type_by_index[index] = field_type;
        hash_by_field_type[field_type] = hash;
    }
    debug_point;
}

BCS_RESULT c_blofeld_field_type_accelerator::get_value(const char* tag_field_type, e_field& field)
{
    blofeld_field_type_accelerator_hash(hash, tag_field_type, k_accelerator_seed);
    uint32_t index = hash & k_accelerator_bit_mask;
    
    e_field field_type = static_cast<e_field>(field_type_by_index[index]);
    if (field_type >= k_number_of_blofeld_field_types) [[unlikely]]
    {
        return BCS_E_FAIL;
    }
    uint32_t expected_hash = hash_by_field_type[field_type];
    if (expected_hash != hash) [[unlikely]]
    {
        return BCS_E_FAIL;
    }
    field = field_type;
    return BCS_S_OK;
}