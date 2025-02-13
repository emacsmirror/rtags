/* This file is part of RTags (https://github.com/Andersbakken/rtags).

   RTags is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   RTags is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with RTags.  If not, see <https://www.gnu.org/licenses/>. */

#include "DependenciesJob.h"

#include <algorithm>

#include "Location.h"
#include "Project.h"
#include "QueryMessage.h"
#include "rct/Flags.h"
#include "rct/Path.h"
#include "rct/Serializer.h"

DependenciesJob::DependenciesJob(const std::shared_ptr<QueryMessage> &query, List<std::shared_ptr<Project>> &&projects)
    : QueryJob(query, std::move(projects), QuietJob)
{
    Deserializer deserializer(query->query());
    Path path;
    deserializer >> path >> mArgs;
    mFileId = Location::fileId(path);
}

int DependenciesJob::execute()
{
    for (const auto &proj : projects()) {
        String ret = proj->dumpDependencies(mFileId, mArgs, queryFlags());
        if (!ret.empty()) {
            write(ret);
            break;
        }
    }
    return 0;
}
