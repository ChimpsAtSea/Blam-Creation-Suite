#pragma once

class h_group;

class c_halo3_tag_group : public c_tag_group
{
public:
	c_halo3_tag_group(c_halo3_cache_cluster& cache_cluster, const blofeld::s_tag_group& blofeld_tag_group, c_halo3_tag_group* parent);
	~c_halo3_tag_group();

	virtual BCS_RESULT get_group_tag(tag& group_tag) const override;
	virtual BCS_RESULT get_group_name(const char*& group_name) const override;
	virtual BCS_RESULT get_group_short_name(const char*& group_short_name) const override;
	virtual BCS_RESULT get_blofeld_tag_group(blofeld::s_tag_group const*& blofeld_tag_group) const override;

private:
	c_cache_cluster& cache_cluster;
	c_halo3_tag_group* parent;
	const blofeld::s_tag_group& blofeld_tag_group;
};

