#ifndef NONCOPYABLE_H_INCLUDED
#define NONCOPYABLE_H_INCLUDED 1

/// @brief Designs data as non-transferrable and prevents access violations.
struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete; // If a copy constructor is called for this type.
    NonCopyable &operator=(const NonCopyable &) = delete; // If a direct copy from an address comes from this type.
};

#endif
