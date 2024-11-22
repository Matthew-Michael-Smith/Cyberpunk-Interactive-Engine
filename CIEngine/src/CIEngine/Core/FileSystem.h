#pragma once

#include "CIEngine/Core/Buffer.h"

namespace CIEngine {

	class FileSystem
	{
	public:
		// TODO: move to FileSystem class
		static Buffer ReadFileBinary(const std::filesystem::path& filepath);
	};

}
