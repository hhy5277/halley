#pragma once
#include "halley/tools/cli_tool.h"

namespace Halley
{
	class DistanceFieldTool : public CommandLineTool
	{
	public:
		int run(Vector<std::string> args) override;
	};
}
