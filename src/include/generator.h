#ifndef _GENERATOR_H_
#define _GENERATOR_H_

void init_generator();
void generate_one(const char *path_to_serialize, const char *out_html_path);
void mutate_one(const char *sample_obj_path, const char *out_html_path);
char r_bool();

#endif
