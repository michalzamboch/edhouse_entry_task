add_rules("mode.debug", "mode.release", "mode.check")

set_languages("c++17")
set_warnings("all", "error")
set_optimize("faster")

target("edhouse_entry_task")
    set_kind("binary")
    add_files("src/*.cpp")
    
    after_build(function (target)
        print("\nbinary: %s", target:name())
        print("target: %s", target:targetfile())
        os.cp("traces/trace.txt", target:targetdir())
    end)
    
    if is_mode("check") then
        set_symbols("debug")
        set_optimize("none")
        add_cxflags("-fsanitize=address", "-ftrapv")
        add_mxflags("-fsanitize=address", "-ftrapv")
        add_ldflags("-fsanitize=address")
    end
