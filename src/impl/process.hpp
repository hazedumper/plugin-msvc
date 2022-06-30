#pragma once

#include <hazedumper/plugin-sdk/process.hpp>

namespace hazedumper::impl {
FINAL_CLASS(msvc_process)
    : public process
{
    auto
    internal_detach() noexcept -> void;

    NODISCARD
    auto
    detect_architecture() noexcept -> bool;

    NODISCARD
    constexpr
    auto
    has_valid_handle() const noexcept -> bool
    {
        return handle_ && handle_ != INVALID_HANDLE_VALUE;
    }

public:
    msvc_process() = default;

    ~msvc_process() override;
    
    auto
    attach(
        std::string_view name
    ) -> bool override;
    
    auto
    attach(
        u32 pid
    ) -> bool override;
    
    auto
    detach() noexcept -> void override;
    
    auto
    get_image(
        std::string_view      name,
        pattern::cache cache_strategy
    ) -> image_ptr override;
    
    auto
    read_mem(
        uptr address,
        ptr  buffer,
        szt  size
    ) const noexcept -> void override;
    
    auto
    write_mem(
        uptr address,
        cptr buffer,
        szt  size
    ) const noexcept -> void override;

    NODISCARD
    auto
    x86() const noexcept -> bool override
    {
        return x86_;
    }

private:
    ptr  handle_{ INVALID_HANDLE_VALUE };
    bool x86_{ false };
};
}
