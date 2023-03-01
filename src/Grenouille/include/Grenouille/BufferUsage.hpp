#pragma once

enum class BufferUsage
{
    CpuAccessNone = 0,
    CpuAccessDynamic = 1,
    CpuAccessReadWrite = 2,
    CpuAccessScratch = 3,
};