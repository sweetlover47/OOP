#include "SeaBattle.h"
#include "GamerFactory.h"
#include "MainOptions.h"
#include <iostream>
#include <string>
#include <memory>
#include "ConsoleView.h"
#include "otherView.h"

//
//static void printError(const char *msg1, const option::Option &opt, const char *msg2) {
//	fprintf(stderr, "ERROR: %s", msg1);
//	fwrite(opt.name, opt.namelen, 1, stderr);
//	fprintf(stderr, "%s", msg2);
//}
//
//static option::ArgStatus PlayerType(const option::Option &option, bool msg) {
//	if (option.arg != nullptr && (strcmp(option.arg, "=random") == 0 || strcmp(option.arg, "=console") == 0 ||
//		strcmp(option.arg, "=optimal") == 0))
//		return option::ARG_OK;
//
//	if (msg)
//		printError("Option '", option, "' requires random/console/optimal type of player\n");
//	return option::ARG_ILLEGAL;
//}
//
//static option::ArgStatus Numeric(const option::Option &option, bool msg) {
//	char *endptr = nullptr;
//	if (option.arg != nullptr && strtol(option.arg, &endptr, 10)) {};
//	if (endptr != option.arg && *endptr == 0)
//		return option::ARG_OK;
//
//	if (msg)
//		printError("Option '", option, "' requires a numeric argument\n");
//	return option::ARG_ILLEGAL;
//}
//
//enum optionIndex {
//	ROUNDS, PLAYER, HELP
//};
//enum optionType {
//	FIRST, SECOND
//};
//
//const option::Descriptor usage[] = {
//	{ ROUNDS, 0,      "c", "count",  Numeric,           "-c, --count \t|Defines number of rounds \t|Default: 1" },
//{ PLAYER, FIRST,  "f", "first",  PlayerType,        "-f, --first \t|Defines type of first player \t|Default: random" },
//{ PLAYER, SECOND, "s", "second", PlayerType,        "-s, --second \t|Defines type of second player \t|Default: random" },
//{ HELP,   0,      "h", "help",   option::Arg::None, "-h, --help \t|Prints out usage of options" }
//};
//
//int main(int argc, char *argv[]) {
//	argc -= (argc > 0);
//	argv += (argc > 0); // skip program name argv[0] if present
//	option::Stats stats(usage, argc, argv);
//	option::Option *options = (option::Option*)calloc(stats.options_max, sizeof(option::Option));
//	option::Option *buffer = (option::Option*)calloc(stats.buffer_max, sizeof(option::Option));
//	option::Parser parse(usage, argc, argv, options, buffer);
//
//	if (parse.error())
//		return 1;
//	if (options[HELP] || argc == 0) {
//		option::printUsage(std::cout, usage);
//		return 0;
//	}
//
//	Gamer *first = nullptr;
//	Gamer *second = nullptr;
//	int rounds = 1;
//
//	if (options[ROUNDS])
//		rounds = atoi(options[ROUNDS].last()->arg);
//	for (option::Option *opt = options[PLAYER]; opt; opt = opt->next()) {
//		switch (opt->type()) {
//		case FIRST:
//			if (first == nullptr)
//				first = GamerFactory::getInstance().getGamer(opt->arg);
//			break;
//		case SECOND:
//			if (second == nullptr)
//				second = GamerFactory::getInstance().getGamer(opt->arg);
//			break;
//		default:
//			return 2;
//		}
//	}

int main(int argc, char **argv)
{
	Gamer *player1 = nullptr, *player2 = nullptr;
	GameView *firstView, *secondView;
	int round = 1;

	MainOptions mo(argc, argv);
	MainOptions::Option* help = mo.getParamFromKey("-h");
	MainOptions::Option* helplong = mo.getParamFromKey("--help");
	if (help || helplong)
		printhelp();

	MainOptions::Option* firstshort = mo.getParamFromKey("-f");
	MainOptions::Option* firstlong = mo.getParamFromKey("--first");
	const std::string typeFirst = firstshort ? (*firstshort).second : (firstlong ? (*firstlong).second : "random");
	player1 = GamerFactory::getInstance().getGamer(typeFirst);
	if (typeFirst == "console")
		firstView = new ConsoleView();
	else
		firstView = new otherView();

	MainOptions::Option* secondshort = mo.getParamFromKey("-s");
	MainOptions::Option* secondlong = mo.getParamFromKey("--second");
	const std::string typeSecond = secondshort ? (*secondshort).second : (secondlong ? (*secondlong).second : "random");
	player2 = GamerFactory::getInstance().getGamer(typeSecond);
	if (typeSecond == "console")
		secondView = new ConsoleView();
	else
		secondView = new otherView();

	MainOptions::Option* countshort = mo.getParamFromKey("-c");
	MainOptions::Option* countlong = mo.getParamFromKey("--count");
	const std::string count = countshort ? (*countshort).second : (countlong ? (*countlong).second : "1");
	round = stoi(count);


	SeaBattle *game = new SeaBattle(firstView, secondView, round);
	game->run(player1, player2);
	system("pause");
	return 0;
}