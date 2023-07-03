#ifndef __BASE_LOADER_TBD_TBD_OBJECT_HH__
#define __BASE_LOADER_TBD_TBD_OBJECT_HH__

#include "base/loader/object_file.hh"


namespace gem5{


    namespace loader{

    class TbdObject : public ObjectFile{

        public:
        /** TODO */
        TbdObject(ImageFileDataPtr dayta);

        /** first we hard wire for 1 gb*/
        Addr mapSize() const override {return ((uint64_t) 1) << 30;};

        MemoryImage buildImage() const override;

    };


    class TbdObjectFileFormat : public ObjectFileFormat{

        public:
        ObjectFile* load(ImageFileDataPtr dayta) override;

    };


    }


}


#endif