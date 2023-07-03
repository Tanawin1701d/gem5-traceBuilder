#include "base/loader/tbd/tbd_object.hh"



namespace gem5{


    namespace loader{


        TbdObject::TbdObject(ImageFileDataPtr objPtr): 
                ObjectFile(objPtr)
        {
            arch = TraceBuilder;
            opSys  = TbdOpSys;

        }

        MemoryImage
        TbdObject::buildImage() const{
            /** for now we use dummy image*/
            auto seg = MemoryImage::Segment("baseSegment", 0, 1 << 30);

            MemoryImage image = MemoryImage(seg);
            
            return image;

        }


        ObjectFile*
        TbdObjectFileFormat::load(ImageFileDataPtr dayta){
            return new TbdObject(dayta);
        }






    }



}