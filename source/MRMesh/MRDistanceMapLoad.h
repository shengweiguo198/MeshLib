#pragma once
#include "MRMeshFwd.h"
#include "MRIOFilters.h"
#include "MRProgressCallback.h"
#include <tl/expected.hpp>
#include <filesystem>

namespace MR
{

namespace DistanceMapLoad
{

/// \defgroup DistanceMapLoadGroup DistanceMap Load
/// \ingroup IOGroup
/// \{

MRMESH_API extern const IOFilters Filters;

/**
 * @brief Load DistanceMap from binary file
 * @detail Format:
 * 2 integer - DistanceMap.resX & DistanceMap.resY
 * [resX * resY] float - matrix of values
 */
MRMESH_API tl::expected<DistanceMap, std::string> loadRaw( const std::filesystem::path& path, ProgressCallback progressCb = {} );

/// \}

} // namespace DistanceMapLoad

} // namespace MR
