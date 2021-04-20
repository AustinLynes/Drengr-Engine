-----------------\\\\\\\ SOLUTION CONFIGURATION ////////// ---------------
-- 
workspace "Drengr Engine"
    architecture "x64"

    configurations {
        "Debug", 
        "Release"
    }


-----------------\\\\\\\ DRENGR API ////////// ---------------
--
project "Drengr"
    location "Drengr"
    kind "StaticLib"
    language "C++"
    -- bin/{Debug/Release}-{Windows/Mac}-{x64}/'Drengr'
    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-x64/%{prj.name}")
    objdir ("bin/%{cfg.buildcfg}-%{cfg.system}-x64/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs  {
        "%{prj.name}/src/"
    }

    filter "system:windows"
        cppdialect      "c++latest"
        staticruntime   "on"
        systemversion   "latest"

        defines {
            "WIN32", "DRENGR_API"
        }

    filter "configurations:Debug"
        defines {"_DEBUG"}
        symbols "on"
        
    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "on"
        symbols "off"




-----------------\\\\\\\ TESTING GROUNDS //////////---------------
--
project "Testing Grounds"
    location "Testing Grounds"
    kind "WindowedApp"
    language "C++"

    --bin/{Debug/Release}-{Windows/Mac}-x64/'Engine Test'
    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-x64/%{prj.name}")
    objdir ("bin/%{cfg.buildcfg}-%{cfg.system}-x64/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Drengr/src/"
    }

    links {
        "Drengr"
    }

    filter "system:windows"
        cppdialect      "c++latest"
        staticruntime   "on"
        systemversion   "latest"

        defines {
            "WIN32"
        }

      
    filter "configurations:Debug"
        defines {"_DEBUG"}
        symbols "on"
        
    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "on"
        symbols "off"
