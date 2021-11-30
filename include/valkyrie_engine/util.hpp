#pragma once

#define VLK_DELETE_COPY_CONSTRUCTORS(VLK_CLASS) \
VLK_CLASS(const VLK_CLASS&) = delete;           \
VLK_CLASS& operator=(const VLK_CLASS&) = delete;

#define VLK_DELETE_MOVE_CONSTRUCTORS(VLK_CLASS) \
VLK_CLASS(VLK_CLASS&&) = delete;                \
VLK_CLASS& operator=(VLK_CLASS&&) = delete;

#define VLK_DEFAULT_COPY_CONSTRUCTORS(VLK_CLASS) \
VLK_CLASS(const VLK_CLASS&) = default;           \
VLK_CLASS& operator=(const VLK_CLASS&) = default;

#define VLK_DEFAULT_MOVE_CONSTRUCTORS(VLK_CLASS) \
VLK_CLASS(VLK_CLASS&&) = default;                \
VLK_CLASS& operator=(VLK_CLASS&&) = default;
