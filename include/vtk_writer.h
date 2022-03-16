/*
 * Author: Xu WANG
 * Created time: 2022-03-14 13:54:36
 * Last Modified by:
 * Last Modified time:
 */
#ifndef _VTK_WRITER_H_
#define _VTK_WRITER_H_

#include <fstream>
#include <kiri_math/kiri_math_mini.h>
using namespace kiri_math_mini;

struct v3
{
    float data[3];
};

struct v2
{
    int data[2];
};

class VTKWriter
{
public:
    VTKWriter(std::string path);
    ~VTKWriter(void);

    void writeParticles(const std::string &fileName,
                        const std::vector<v3> pos);

private:
    std::string mExportPath;
    std::ofstream *mExportFile;
    std::vector<std::string> mAttributes;

    void createParticleFile(const std::string &fileName);

    // VTK expects big endian
    template <typename T>
    inline void swapByteOrder(T *v)
    {
        constexpr size_t n = sizeof(T);
        uint8_t *bytes = reinterpret_cast<uint8_t *>(v);
        for (unsigned int c = 0u; c < n / 2; c++)
            std::swap(bytes[c], bytes[n - c - 1]);
    }
};

#endif
