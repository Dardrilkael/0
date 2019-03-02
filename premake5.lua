workspace "Hammer"
architecture "x64"
configurations {"Dist","Release","Debug"}
startproject "SandBox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hammer"
location "Hammer"
kind "SharedLib"
language "C++"
staticruntime "off"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

includedirs 
{
"%{prj.name}/src",
"%{prj.name}/vendor/spdlog/include"
}

files
{

	"%{prj.name}/src/**.cpp",
	"%{prj.name}/src/**.h"
}

postbuildcommands
{
	("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
}

filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		defines
	{
		"HM_PLATFORM_WINDOWS",
		"HM_BUILD_DLL"
	}


filter "configurations:Dist"
optimize "On"
symbols "Off"

	defines
	{
		"HM_DIST"
	}

filter "configurations:Release"
optimize "On"
symbols "On"
defines
{
	"HM_RELEASE"
}

filter "configurations:Debug"
symbols "On"
defines
{
	"HM_DEBUG"
}

project "SandBox"
location "SandBox"
kind "ConsoleApp"
language "C++"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

files
{
	"%{prj.name}/src/**.cpp",
	"%{prj.name}/src/**.h"
}

includedirs
{
	"%{prj.name}/src",
	"Hammer/vendor/spdlog/include",
	"Hammer/src"
}

links 
{
	"Hammer"
}

filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		defines
		{
			"HM_PLATFORM_WINDOWS"
		}