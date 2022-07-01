#include <hazedumper/plugin-sdk/plugin.hpp>
#include <hazedumper/plugin-sdk/dependencies.hpp>
#include "impl/process.hpp"

using namespace hazed;

FINAL_CLASS(hazedumper_msvc)
    : public plugin
{
public:
    explicit
    hazedumper_msvc(
        const u32 major,
        const u32 minor,
        const u32 patch
    ) noexcept
        : plugin(major, minor, patch)
    {}

    NODISCARD
    auto
    name() const noexcept -> std::string_view override
    {
        return "hazedumper-msvc";
    }

    NODISCARD
    auto
    author() const noexcept -> std::string_view override
    {
        return "hazedumper";
    }

    NODISCARD
    auto
    description() const noexcept -> std::string_view override
    {
        return "Remote process abstraction layer for Windows";
    }

    NODISCARD
    auto
    priority() const noexcept -> i32 override
    {
        return 20;
    }

    NODISCARD
    auto
    load() -> bool override
    {
        return true;
    }

    NODISCARD
    auto
    unload() -> void override
    {}

    NODISCARD
    auto
    update_dependencies(
        const dependencies_ptr& deps
    ) -> void override
    {
        deps->process(std::make_shared<impl::msvc_process>());
    }
};

HAZEDUMPER_PLUGIN(hazedumper_msvc, 0, 2, 0);
