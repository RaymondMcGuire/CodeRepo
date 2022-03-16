/*
 * Author: Xu WANG
 * Created time: 2022-03-14 13:57:23
 * Last Modified by:
 * Last Modified time:
 */

#include <vtk_writer.h>

VTKWriter::VTKWriter(std::string path)
{
    mExportFile = nullptr;
    mExportPath = path;
}
VTKWriter::~VTKWriter(void)
{
}

void VTKWriter::createParticleFile(const std::string &fileName)
{

    mExportPath += fileName;
    std::cout << mExportPath << std::endl;
    // Open the file
    mExportFile = new std::ofstream(mExportPath, std::ios::binary);
    if (!mExportFile->is_open())
    {
        std::cout << "Cannot open a file to save VTK particles." << std::endl;
        return;
    }

    *mExportFile << "# vtk DataFile Version 4.1\n";
    *mExportFile << "SeepageFlow Particle Data\n"; // title of the data set, (any string up to 256 characters+\n)
    *mExportFile << "BINARY\n";
    *mExportFile << "DATASET UNSTRUCTURED_GRID\n";

    mAttributes.clear();
    //! TODO add attributes

    // positions and ids exported anyways
    mAttributes.erase(
        std::remove_if(mAttributes.begin(), mAttributes.end(), [](const std::string &s)
                       { return (s == "position" || s == "id"); }),
        mAttributes.end());
}

void VTKWriter::writeParticles(
    const std::string &fileName,
    const std::vector<v3> pos)
{
    const char *real_str = " float\n";

    const unsigned int numParticles = pos.size();

    std::vector<v3> positions;
    positions.reserve(numParticles);
    std::vector<v2> cells;
    cells.reserve(numParticles);
    std::vector<int> cellTypes;
    cellTypes.reserve(numParticles);
    std::vector<unsigned int> attrData;
    attrData.reserve(numParticles);

    unsigned int counter = 0;
    for (unsigned int i = 0; i < numParticles; i++)
    {
        // export position attribute as POINTS
        {
            positions.push_back(pos[i]);
            // swap endianess
            for (unsigned int c = 0; c < 3; c++)
                swapByteOrder(&positions[positions.size() - 1].data[c]);
        }

        // export particle IDs as CELLS
        {
            unsigned int nodes_per_cell_swapped = 1;
            swapByteOrder(&nodes_per_cell_swapped);
            unsigned int idSwapped = counter++;
            swapByteOrder(&idSwapped);
            v2 v;
            v.data[0] = nodes_per_cell_swapped;
            v.data[1] = idSwapped;
            cells.push_back(v);
            attrData.push_back(idSwapped);
        }
        //////////////////////////////////////////////////////////////////////////
        // export cell types
        {
            // the type of a particle cell is always 1
            int cellTypeSwapped = 1;
            swapByteOrder(&cellTypeSwapped);
            cellTypes.push_back(cellTypeSwapped);
        }

        //////////////////////////////////////////////////////////////////////////
        // write additional attributes as per-particle data
        {
            unsigned int id = i;
            swapByteOrder(&id);
            attrData.push_back(id);
        }
    }

    createParticleFile(fileName);

    if (mExportFile != nullptr)
    {
        // export to vtk
        const unsigned int nPoints = (unsigned int)positions.size();
        *mExportFile << "POINTS " << nPoints << real_str;
        mExportFile->write(reinterpret_cast<char *>(positions[0].data), 3 * nPoints * sizeof(float));
        *mExportFile << "\n";

        // particles are cells with one element and the index of the particle
        *mExportFile << "CELLS " << nPoints << " " << 2 * nPoints << "\n";
        mExportFile->write(reinterpret_cast<char *>(cells[0].data), 2 * nPoints * sizeof(unsigned int));
        *mExportFile << "\n";

        *mExportFile << "CELL_TYPES " << nPoints << "\n";
        mExportFile->write(reinterpret_cast<char *>(cellTypes.data()), nPoints * sizeof(int));
        *mExportFile << "\n";

        *mExportFile << "POINT_DATA " << nPoints << "\n";
        // write IDs
        *mExportFile << "SCALARS id unsigned_int 1\n";
        *mExportFile << "LOOKUP_TABLE id_table\n";
        mExportFile->write(reinterpret_cast<char *>(attrData.data()), nPoints * sizeof(unsigned int));
        *mExportFile << "\n";

        //////////////////////////////////////////////////////////////////////////
        // per point fields (all attributes except for positions)
        // const auto numFields = mAttributes.size();
        // *mExportFile << "FIELD FieldData " << std::to_string(numFields) << "\n";

        // 	// iterate over attributes
        // for (const std::string& a : mAttributes)
        // {
        // 	const FieldDescription& field = model->getField(a);

        // 	if (field.type == FieldType::Scalar)
        // 	{
        // 		// write header information
        // 		*mExportFile << attrNameVTK << " 1 " << nPoints << real_str;

        // 		// copy data
        // 		std::vector<Real> attrData;
        // 		attrData.reserve(nPoints);
        // 		for (unsigned int i = 0u; i < numParticles; i++)
        // 		{
        // 			if ((objId != 0xffffffff) && (model->getObjectId(i) != objId))
        // 				continue;
        // 			Real val = *((Real*)field.getFct(i));
        // 			swapByteOrder(&val);		// swap endianess
        // 			attrData.emplace_back(val);
        // 		}

        // 		// export to vtk
        // 		m_outfile->write(reinterpret_cast<char*>(attrData.data()), nPoints * sizeof(Real));
        // 	}
        // 	else if (field.type == FieldType::Vector3)
        // 	{
        // 		// write header information
        // 		*mExportFile << attrNameVTK << " 3 " << nPoints << real_str;

        // 		// copy from partio data
        // 		std::vector<Vector3r> attrData;
        // 		attrData.reserve(nPoints);
        // 		for (unsigned int i = 0u; i < numParticles; i++)
        // 		{
        // 			if ((objId != 0xffffffff) && (model->getObjectId(i) != objId))
        // 				continue;
        // 			Vector3r val((Real*)field.getFct(i));
        // 			for (unsigned int c = 0; c < 3; c++)
        // 				swapByteOrder(&val[c]);		// swap endianess
        // 			attrData.emplace_back(val);
        // 		}
        // 		// export to vtk
        // 		m_outfile->write(reinterpret_cast<char*>(attrData[0].data()), 3 * nPoints * sizeof(Real));
        // 	}
        // 	else if (field.type == FieldType::UInt)
        // 	{
        // 		// write header information
        // 		*mExportFile << attrNameVTK << " 1 " << nPoints << " unsigned_int\n";

        // 		// copy data
        // 		std::vector<unsigned int> attrData;
        // 		attrData.reserve(nPoints);
        // 		for (unsigned int i = 0u; i < numParticles; i++)
        // 		{
        // 			if ((objId != 0xffffffff) && (model->getObjectId(i) != objId))
        // 				continue;
        // 			unsigned int val = *((unsigned int*)field.getFct(i));
        // 			swapByteOrder(&val);		// swap endianess
        // 			attrData.emplace_back(val);
        // 		}
        // 		// export to vtk
        // 		m_outfile->write(reinterpret_cast<char*>(attrData.data()), nPoints * sizeof(unsigned int));
        // 	}
        // 	// TODO support other field types
        // 	else
        // 	{
        // 		LOG_WARN << "Skipping attribute " << a << ", because it is of unsupported type\n";
        // 		continue;
        // 	}
        // 	// end of block
        // 	*mExportFile << "\n";

        // }

        mExportFile->close();
        delete mExportFile;
        mExportFile = nullptr;
    }
}