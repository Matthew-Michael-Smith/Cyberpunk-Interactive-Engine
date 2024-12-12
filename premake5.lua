include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "CIEngine"
	architecture "x86_64"
	startproject "CIEngine-Dev"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "CIEngine/vendors/Box2D"
	include "CIEngine/vendors/GLFW"
	include "CIEngine/vendors/Glad"
	include "CIEngine/vendors/msdf-atlas-gen"
	include "CIEngine/vendors/imgui"
	include "CIEngine/vendors/yaml-cpp"
group ""

group "Core"
	include "CIEngine"
	include "CIEngine-ScriptCore"
group ""

group "Tools"
	include "CIEngine-Dev"
group ""

group "Misc"
	include "DaredevilSOTH"
group ""
