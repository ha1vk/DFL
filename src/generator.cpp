#include "document_html.h"
#include "HIRMutate/src/include/config.h"
#include "serializestream.h"
#include "init.h"
#include <fcntl.h>
#include <unistd.h>
#include "random.h"

extern "C"
{
    void init_generator()
    {
        HIRMutate::init();
    }
    void generate_one(const char *path_to_serialize, const char *out_html_path)
    {
        HIRMutate::Document::ptr document = std::make_shared<HIRMutate::Document>(HIRMutate::Random::range(HIRMutate::TreeConfig::min_element_count, HIRMutate::TreeConfig::max_element_count));
        document->generate_nodes();
        document->generate_attributes();
        document->generate_css_rules();
        document->generate_js_functions();
        string s = document->operator string();
        int fd = open(out_html_path, O_RDWR | O_CREAT | O_TRUNC, 0777);
        write(fd, s.c_str(), s.length());
        close(fd);
        HIRMutate::SerializeStream *stream = new HIRMutate::SerializeStream();
        document->serialize(stream);
        stream->write_to_file(path_to_serialize);
        delete stream;
    }

    void mutate_one(const char *sample_obj_path, const char *out_html_path)
    {
        string obj_path = sample_obj_path;
        HIRMutate::Document::ptr document = std::make_shared<HIRMutate::Document>();
        HIRMutate::UnSerializeStream *stream = new HIRMutate::UnSerializeStream(sample_obj_path);
        document->unserialize(stream);
        delete stream;
        int selector = HIRMutate::Random::selector(4);
        if (selector == 0)
            document->fuzz_css();
        else if (selector == 1)
            document->fuzz_dom_tree();
        else if (selector == 2)
            document->fuzz_js_functions();
        else
        {
            document->fuzz_css();
            document->fuzz_dom_tree();
            document->fuzz_js_functions();
        }
        string s = document->operator string();
        int fd = open(out_html_path, O_RDWR | O_CREAT | O_TRUNC, 0777);
        write(fd, s.c_str(), s.length());
        close(fd);
        obj_path.append(".mutate");
        //序列化
        HIRMutate::SerializeStream *ser_stream = new HIRMutate::SerializeStream();
        document->serialize(ser_stream);
        ser_stream->write_to_file(obj_path);
        delete ser_stream;
    }

    char r_bool()
    {
        return HIRMutate::Random::gbool();
    }
}