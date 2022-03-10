/*
	Changed file name from MQ2SpellSearch.h to MQ2SpellSearchH.h
	to avoid any potential naming conflict with the one in src/main.
*/

class MQSpellSearchType;

struct SpellSearch
{
private:

	// Default values of filter settings.
	const bool defCanScribe = false;
	const bool defShowSpellEffects = false;

	// Only spells the char can use are shown unless true.
	const bool defShowAll = false;
	const bool defShowMissingSpellsOnly = false;
	const bool defShowReverse = false;
	const bool defShowLastRecord = false;
	const bool defShowFirstRecord = false;

	const bool defShowDetailedOutput = false;
	const bool defSpellRecordGiven = false;
	const int  defVectorRecord = 0;

	// Only show spells that are relevant to pchar classlevel.
	const bool defIgnoreClass = false;

	// Not sure of the intention.  I'm assuming that the rank
	// need not be shown. "spell", "spell rk. II", "spell rk. III"
	// should just show "spell", screening duplicates.
	const bool defIgnoreRank = false;

	const bool defDebug = false;

	int eEQSPArev[sizeof(eEQSPA)];

public:

	// User supplied args
	std::string RawQuery = "";

	// Spell Data
	int         ID = -1;
	std::string Name = "";
	std::string PartialName = "";
	std::string Class = "";
	int			ClassID = -1;
	bool		ClassFlag = false;
	int         MinLevel = 1;
	int         MaxLevel = 1;
	std::string Category = "";
	int         nCategory = -1;
	std::string SubCategory = "";
	int         nSubCategory = -1;
	std::string SubCategory2 = "";
	int			nSubCategory2 = -1;

	int         Timer = -1;
	bool		SpellRecordGiven = defSpellRecordGiven;
	bool		IgnoreClass = defIgnoreClass;
	bool		ShowAll = defShowAll;
	int			Reflectable = -1;
	int			Feedbackable = -1;
	double		MinRange = -1;
	double		MaxRange = -1;
	double		AERange = -1;
	int			SpreadRadius = -1;
	int			PushBack = -1;
	int			PushUp = -1;
	int			HateGenerated = -1;
	int			TargetType = -1;
	int			NumEffectsMin = -1;
	int			NumEffectsMax = -1;
	int			Skill = -1;
	int			MaxTargetsMin = -1;
	int			MaxTargetsMax = -1;
	int			ResistType = -1;
	int			CastTimeMin = -1;
	int			CastTimeMax = -1;
	int			RecastTimeMin = -1;
	int			RecastTimeMax = -1;
	std::string AltAbility = "";
	int			nAltAbility = -1;
	bool		AltAbilityFilter = false;

	// Use to search through spelleffects for keyword or phrase.
	std::string SpellEffect = "";
	// Assumes a match is wanted. False means not found anywhere.
	bool		bSpellEffectMod = true;

	// As implemented, allows 1 SPA lookup
	std::string SPA = "";
	int			nSPA = -1;
	// Assumes a match is wanted. False means not found anywhere.
	bool		bSPAMod = true;

	// Partial match in the Extra field for procs, etc
	std::string Extra = "";

	// Configuration settings - filters/views
	bool CanScribe = defCanScribe;
	bool ShowSpellEffects = defShowSpellEffects;
	bool ShowMissingSpellsOnly = defShowMissingSpellsOnly;
	bool ShowFirstRecord = defShowFirstRecord;
	bool ShowLastRecord = defShowLastRecord;
	bool ShowReverse = defShowReverse;
	bool ShowDetailedOutput = defShowDetailedOutput;
	int  VectorRecord = defVectorRecord;
	bool IgnoreRank = defIgnoreRank;
	int	 TriggerIndex = -1;
	bool WikiTableFormat = false;
	bool CleanFormat = false;

	bool Debug = defDebug;

	// Allow comparison of SpellSearch objects. Data only / params given by user, not looked up like nCategory.
	bool SpellSearch::operator==(const SpellSearch& pOther) const
	{
		if (
			ID == pOther.ID &&
			Name == pOther.Name &&
			PartialName == pOther.PartialName &&
			Class == pOther.Class &&
			ClassID == pOther.ClassID &&
			ClassFlag == pOther.ClassFlag &&
			MinLevel == pOther.MinLevel &&
			MaxLevel == pOther.MaxLevel &&
			Category == pOther.Category &&
			SubCategory == pOther.SubCategory &&
			SubCategory2 == pOther.SubCategory2 &&

			Timer == pOther.Timer &&
			SpellRecordGiven == pOther.SpellRecordGiven &&
			IgnoreClass == pOther.IgnoreClass &&
			ShowAll == pOther.ShowAll &&

			Reflectable == pOther.Reflectable &&
			Feedbackable == pOther.Feedbackable &&
			MinRange == pOther.MinRange &&
			MaxRange == pOther.MaxRange &&
			AERange == pOther.AERange &&
			SpreadRadius == pOther.SpreadRadius &&
			PushBack == pOther.PushBack &&
			PushUp == pOther.PushUp &&
			HateGenerated == pOther.HateGenerated &&
			TargetType == pOther.TargetType &&
			NumEffectsMin == pOther.NumEffectsMin &&
			NumEffectsMax == pOther.NumEffectsMax &&
			Skill == pOther.Skill &&
			MaxTargetsMin == pOther.MaxTargetsMin &&
			MaxTargetsMax == pOther.MaxTargetsMax &&
			ResistType == pOther.ResistType &&
			CastTimeMin == pOther.CastTimeMin &&
			CastTimeMax == pOther.CastTimeMax &&
			RecastTimeMin == pOther.RecastTimeMin &&
			RecastTimeMax == pOther.RecastTimeMax &&
			AltAbility == pOther.AltAbility &&
			nAltAbility == pOther.nAltAbility &&
			AltAbilityFilter == pOther.AltAbilityFilter &&
			SpellEffect == pOther.SpellEffect &&
			bSpellEffectMod == pOther.bSpellEffectMod &&
			SPA == pOther.SPA &&
			bSPAMod == pOther.bSPAMod &&
			Extra == pOther.Extra
			)
			return true;
		return false;
	}

	// Allow comparison of SpellSearch objects. Data only.
	bool SpellSearch::operator!=(const SpellSearch& pOther) const
	{
		if (
			ID != pOther.ID ||
			Name != pOther.Name ||
			PartialName != pOther.PartialName ||
			Class != pOther.Class ||
			ClassID != pOther.ClassID ||
			ClassFlag != pOther.ClassFlag ||
			ClassFlag != pOther.ClassFlag ||
			MinLevel != pOther.MinLevel ||
			MaxLevel != pOther.MaxLevel ||
			Category != pOther.Category ||
			SubCategory != pOther.SubCategory ||
			SubCategory2 != pOther.SubCategory2 ||

			Timer != pOther.Timer ||
			SpellRecordGiven != pOther.SpellRecordGiven ||
			IgnoreClass != pOther.IgnoreClass ||
			ShowAll != pOther.ShowAll ||

			Reflectable != pOther.Reflectable ||
			Feedbackable != pOther.Feedbackable ||
			MinRange != pOther.MinRange ||
			MaxRange != pOther.MaxRange ||
			AERange != pOther.AERange ||
			SpreadRadius != pOther.SpreadRadius ||
			PushBack != pOther.PushBack ||
			PushUp != pOther.PushUp ||
			HateGenerated != pOther.HateGenerated ||
			TargetType != pOther.TargetType ||
			NumEffectsMin != pOther.NumEffectsMin ||
			NumEffectsMax != pOther.NumEffectsMax ||
			Skill != pOther.Skill ||
			MaxTargetsMin != pOther.MaxTargetsMin ||
			MaxTargetsMax != pOther.MaxTargetsMax ||
			ResistType != pOther.ResistType ||
			CastTimeMin != pOther.CastTimeMin ||
			CastTimeMax != pOther.CastTimeMax ||
			RecastTimeMin != pOther.RecastTimeMin ||
			RecastTimeMax != pOther.RecastTimeMax ||
			AltAbility != pOther.AltAbility ||
			nAltAbility != pOther.nAltAbility ||
			AltAbilityFilter != pOther.AltAbilityFilter ||
			SpellEffect != pOther.SpellEffect ||
			bSpellEffectMod != pOther.bSpellEffectMod ||
			SPA != pOther.SPA ||
			bSPAMod != pOther.bSPAMod ||
			Extra != pOther.Extra
			)
			return true;
		return false;
	}

	void CacheData(const SpellSearch& pOther)
	{
		// User supplied args
		RawQuery = pOther.RawQuery;

		// Data
		ID = pOther.ID;
		Name = pOther.Name;
		PartialName = pOther.PartialName;
		Class = pOther.Class;
		ClassID = pOther.ClassID;
		ClassFlag = pOther.ClassFlag;
		MinLevel = pOther.MinLevel;
		MaxLevel = pOther.MaxLevel;
		Category = pOther.Category;
		nCategory = pOther.nCategory;
		SubCategory = pOther.SubCategory;
		nSubCategory = pOther.nSubCategory;
		SubCategory2 = pOther.SubCategory2;
		nSubCategory2 = pOther.nSubCategory2;

		Timer = pOther.Timer;
		SpellRecordGiven = pOther.SpellRecordGiven;
		IgnoreClass = pOther.IgnoreClass;
		ShowAll = pOther.ShowAll;

		Reflectable = pOther.Reflectable;
		Feedbackable = pOther.Feedbackable;
		MinRange = pOther.MinRange;
		MaxRange = pOther.MaxRange;
		AERange = pOther.AERange;
		SpreadRadius = pOther.SpreadRadius;
		PushBack = pOther.PushBack;
		PushUp = pOther.PushUp;
		HateGenerated = pOther.HateGenerated;
		TargetType = pOther.TargetType;
		NumEffectsMin = pOther.NumEffectsMin;
		NumEffectsMax = pOther.NumEffectsMax;
		Skill = pOther.Skill;
		MaxTargetsMin = pOther.MaxTargetsMin;
		MaxTargetsMax = pOther.MaxTargetsMax;
		ResistType = pOther.ResistType;
		CastTimeMin = pOther.CastTimeMin;
		CastTimeMax = pOther.CastTimeMax;
		RecastTimeMin = pOther.RecastTimeMin;
		RecastTimeMax = pOther.RecastTimeMax;
		AltAbility = pOther.AltAbility;
		nAltAbility = pOther.nAltAbility;
		AltAbilityFilter = pOther.AltAbilityFilter;
		SpellEffect = pOther.SpellEffect;
		bSpellEffectMod = pOther.bSpellEffectMod;
		SPA = pOther.SPA;
		nSPA = pOther.nSPA;
		bSPAMod = pOther.bSPAMod;
		Extra = pOther.Extra;
	}

	void CacheView(const SpellSearch& pOther)
	{
		// View
		CanScribe = pOther.CanScribe;
		ShowSpellEffects = pOther.ShowSpellEffects;
		ShowMissingSpellsOnly = pOther.ShowMissingSpellsOnly;
		ShowReverse = pOther.ShowReverse;
		ShowFirstRecord = pOther.ShowFirstRecord;
		ShowLastRecord = pOther.ShowLastRecord;
		ShowDetailedOutput = pOther.ShowDetailedOutput;
		VectorRecord = pOther.VectorRecord;
		IgnoreRank = pOther.IgnoreRank;
		TriggerIndex = pOther.TriggerIndex;
		WikiTableFormat = pOther.WikiTableFormat;
		CleanFormat = pOther.CleanFormat;
		Debug = pOther.Debug;
	}

	void ShowData()
	{
		WriteChatf("ShowData :: RawQuery                [%s]", RawQuery.c_str());
		WriteChatf("ShowData :: ID                      [%i]", ID);
		WriteChatf("ShowData :: Name                    [%s]", Name.c_str());
		WriteChatf("ShowData :: PartialName             [%s]", PartialName.c_str());
		WriteChatf("ShowData :: Class                   [%s]", Class.c_str());
		WriteChatf("ShowData :: ClassID                 [%i]", ClassID);
		WriteChatf("ShowData :: ClassFlag               [%d]", ClassFlag);
		WriteChatf("ShowData :: MinLevel                [%i]", MinLevel);
		WriteChatf("ShowData :: MaxLevel                [%i]", MaxLevel);
		WriteChatf("ShowData :: Category                [%s]", Category.c_str());
		WriteChatf("ShowData :: nCategory               [%i]", nCategory);
		WriteChatf("ShowData :: SubCategory             [%s]", SubCategory.c_str());
		WriteChatf("ShowData :: nSubCategory            [%i]", nSubCategory);
		WriteChatf("ShowData :: SubCategory2            [%s]", SubCategory2.c_str());
		WriteChatf("ShowData :: nSubCategory2           [%i]", nSubCategory2);
		WriteChatf("ShowData :: Timer                   [%i]", Timer);
		WriteChatf("ShowData :: SpellRecordGiven        [%d]", SpellRecordGiven);
		WriteChatf("ShowData :: IgnoreClass             [%d]", IgnoreClass);
		WriteChatf("ShowData :: ShowAll                 [%d]", ShowAll);
		WriteChatf("ShowData :: Reflectable             [%i]", Reflectable);
		WriteChatf("ShowData :: Feedbackable            [%i]", Feedbackable);
		WriteChatf("ShowData :: MinRange                [%4.2f]", MinRange);
		WriteChatf("ShowData :: MaxRange                [%4.2f]", MaxRange);
		WriteChatf("ShowData :: AERange                 [%4.2f]", AERange);
		WriteChatf("ShowData :: SpreadRadius            [%i]", SpreadRadius);
		WriteChatf("ShowData :: PushBack                [%i]", PushBack);
		WriteChatf("ShowData :: PushUp                  [%i]", PushBack);
		WriteChatf("ShowData :: HateGenerated           [%i]", HateGenerated);
		WriteChatf("ShowData :: TargetType              [%i]", TargetType);
		WriteChatf("ShowData :: NumEffectsMin           [%i]", NumEffectsMin);
		WriteChatf("ShowData :: NumEffectsMax           [%i]", NumEffectsMax);
		WriteChatf("ShowData :: Reflectable             [%i]", Reflectable);
		WriteChatf("ShowData :: Skill                   [%i]", Skill);
		WriteChatf("ShowData :: MaxTargetsMin           [%i]", MaxTargetsMin);
		WriteChatf("ShowData :: MaxTargetsMax           [%i]", MaxTargetsMax);
		WriteChatf("ShowData :: ResistType              [%i]", ResistType);
		WriteChatf("ShowData :: SpellEffect             [%s]", SpellEffect.c_str());
		WriteChatf("ShowData :: bSpellEffectMod         [%d]", bSpellEffectMod);
		WriteChatf("ShowData :: SPA                     [%s]", SPA.c_str());
		WriteChatf("ShowData :: nSPA                    [%i]", nSPA);
		WriteChatf("ShowData :: bSPAMod                 [%i]", bSPAMod);
		WriteChatf("ShowData :: Extra                   [%i]", Extra);
	}

	void ShowView()
	{
		WriteChatf("ShowView :: CanScribe               [%d]", CanScribe);
		WriteChatf("ShowView :: ShowSpellEffects        [%d]", ShowSpellEffects);
		WriteChatf("ShowView :: ShowMissingSpellsOnly   [%d]", ShowMissingSpellsOnly);
		WriteChatf("ShowView :: ShowReverse             [%d]", ShowReverse);
		WriteChatf("ShowView :: ShowFirstRecord         [%d]", ShowFirstRecord);
		WriteChatf("ShowView :: ShowLastRecord          [%d]", ShowLastRecord);
		WriteChatf("ShowView :: ShowDetailedOutput      [%d]", ShowDetailedOutput);
		WriteChatf("ShowView :: VectorRecord            [%i]", VectorRecord);
		WriteChatf("ShowView :: IgnoreRank              [%d]", IgnoreRank);
		WriteChatf("ShowView :: TriggerIndex            [%i]", TriggerIndex);
		WriteChatf("ShowView :: WikiTableFormat         [%d]", WikiTableFormat);
		WriteChatf("ShowView :: CleanFormat             [%d]", CleanFormat);
		WriteChatf("ShowView :: Debug                   [%i]", Debug);
	}

	void Clear()
	{
		RawQuery = "";

		ID = -1;
		Name = "";
		PartialName = "";
		Class = "";
		ClassID = -1;
		ClassFlag = false;
		MinLevel = 1;
		MaxLevel = 1;
		Category = "";
		nCategory = -1;
		SubCategory = "";
		nSubCategory = -1;
		SubCategory2 = "";
		nSubCategory2 = -1;

		Timer = -1;
		SpellRecordGiven = defSpellRecordGiven;
		IgnoreClass = defIgnoreClass;
		ShowAll = defShowAll;

		Reflectable = -1;
		Feedbackable = -1;
		MinRange = -1;
		MaxRange = -1;
		AERange = -1;
		SpreadRadius = -1;
		PushBack = -1;
		PushUp = -1;
		HateGenerated = -1;
		TargetType = -1;
		NumEffectsMin = -1;
		NumEffectsMax = -1;
		Skill = -1;
		SpellEffect = "";
		bSpellEffectMod = true;
		MaxTargetsMin = -1;
		MaxTargetsMax = -1;
		ResistType = -1;
		CastTimeMin = -1;
		CastTimeMax = -1;
		RecastTimeMin = -1;
		RecastTimeMax = -1;
		AltAbility = "";
		nAltAbility = -1;
		AltAbilityFilter = false;

		SPA = "";
		nSPA = -1;
		bSPAMod = true;
		Extra = "";

		CanScribe = defCanScribe;
		ShowSpellEffects = defShowSpellEffects;
		ShowMissingSpellsOnly = defShowMissingSpellsOnly;
		ShowReverse = defShowReverse;
		ShowFirstRecord = defShowFirstRecord;
		ShowLastRecord = defShowLastRecord;
		ShowDetailedOutput = defShowDetailedOutput;
		VectorRecord = defVectorRecord;
		IgnoreRank = defIgnoreRank;
		TriggerIndex = -1;
		WikiTableFormat = false;
		CleanFormat = false;
		Debug = defDebug;
	}
};

std::unordered_map<std::string, int> m_ClassNameAcronym =
{
	{"000",              0},
	{"WAR",              1},
	{"CLR",              2},
	{"PAL",              3},
	{"RNG",              4},
	{"SHD",              5},
	{"DRU",              6},
	{"MNK",              7},
	{"BRD",              8},
	{"ROG",              9},
	{"SHM",              10},
	{"NEC",              11},
	{"WIZ",              12},
	{"MAG",              13},
	{"ENC",              14},
	{"BST",              15},
	{"BER",              16},
};

std::string ClassName[] =
{
	"Any",              //-1,
	"Warrior",          //1,
	"Cleric",           //2,
	"Paladin",          //3,
	"Ranger",           //4,
	"Shadow Knight",    //5,
	"Druid",            //6,
	"Monk",             //7,
	"Bard",             //8,
	"Rogue",            //9,
	"Shaman",           //10,
	"Necromancer",      //11,
	"Wizard",           //12,
	"Magician",         //13,
	"Enchanter",        //14,
	"Beastlord",        //15,
	"Berserker",        //16,
};

std::string ClassNameAcronym[] =
{
	"Any",              //-1,
	"WAR",              //1,
	"CLR",              //2,
	"PAL",              //3,
	"RNG",              //4,
	"SHD",              //5,
	"DRU",              //6,
	"MNK",              //7,
	"BRD",              //8,
	"ROG",              //9,
	"SHM",              //10,
	"NEC",              //11,
	"WIZ",              //12,
	"MAG",              //13,
	"ENC",              //14,
	"BST",              //15,
	"BER",              //16,
};

/*
struct
{
	char* name;
	int classn;
} classes[] = {
	"any",              -1,
	"bard",             8,
	"beastlord",        15,
	"berserker",        16,
	"cleric",           2,
	"druid",            6,
	"enchanter",        14,
	"magician",         13,
	"monk",             7,
	"necromancer",      11,
	"paladin",          3,
	"ranger",           4,
	"rogue",            9,
	"shadow knight",    5,
	"shaman",           10,
	"warrior",          1,
	"wizard",           12,
};
*/

std::string TargetTypeAcronym[] =
{
	"NONE",      //TargetType_None = 0,
	"LOS",       //TargetType_LineOfSight = 1,
	"AEPCINRNG", //TargetType_AEPC_v1 = 2,                 // players in area around caster
	"GROUPNEAR", //TargetType_Group_v1 = 3,                // group members around caster
	"PBAE",      //TargetType_PBAE = 4,                    // area around caster
	"SINGLE",    //TargetType_Single = 5,                  // current target
	"SELF",      //TargetType_Self = 6,                    // targets self only
	"UNKN7",
	"AREA",      //TargetType_TargetArea = 8,              // radius around target
	"ANIMAL",    //TargetType_TargetAnimal = 9,
	"UNDEAD",    //TargetType_TargetUndead = 10,
	"SUMMONED",  //TargetType_TargetSummoned = 11,
	"UNKN12",
	"DRAIN",     //TargetType_TargetDrain = 13,
	"MYPET",     //TargetType_Pet = 14,                    // caster's pet
	"CORPSE",    //TargetType_TargetCorpse = 15,
	"PLANT",     //TargetType_TargetPlant = 16,
	"GIANT",     //TargetType_TargetGiants = 17,
	"DRAGON",    //TargetType_TargetDragons = 18,
	"COLDAIN",   //TargetType_TargetColdain = 19,
	"AEDRAIN",   //TargetType_TargetAEDrain = 20,
	"UNKN21",
	"UNKN22",
	"UNKN23",
	"AEUNDEAD",  //TargetType_TargetAEUndead = 24,
	"AESUMMON",  //TargetType_TargetAESummoned = 25,
	"UNKN26",
	"UNKN27",
	"UNKN28",
	"UNKN29",
	"UNKN30",
	"UNKN31",
	"HATEINRNG", //TargetType_HateList = 32,               // all players on hatelist in range
	"HATEOOR",   //TargetType_HateList_All = 33,           // all players on hatelist regardless of range
	"CURSED",    //TargetType_TargetCursed = 34,
	"MURAMITE",  //TargetType_TargetMuramite = 35,
	"AEPCv2",    //TargetType_CasterAreaPC = 36,
	"AENPC",     //TargetType_CasterAreaNPC = 37,
	"PET",       //TargetType_Pet_v2 = 38,                 // targeted pet
	"PC",        //TargetType_TargetPC = 39,               // targeted player
	"AEPCBNFIT", //TargetType_AEPC_v2 = 40,                // area beneficial players
	"GROUP",     //TargetType_Group_v2 = 41,               // area grouped players
	"CONE",      //TargetType_DirectionalCone = 42,        // projected cone in front of player
	"GROUPEDPC", //TargetType_SingleGrouped = 43,          // single target grouped
	"BEAM",      //TargetType_Beam = 44,
	"AEFREE",    //TargetType_FreeTarget = 45,             // player picks a point in space
	"TARGETOF",  //TargetType_TargetOfTarget = 46,
	"PETOWNER",  //TargetType_PetOwner = 47,               // cast on pet's owner
	"UNKN48",
	"UNKN49",
	"AEDETRMTL", //TargetType_AreaDetrimental = 50,        // targets enemies of caster
	"UNKN51",
	"BENEFIT",   //TargetType_TargetBeneficial = 52,
};

std::unordered_map<std::string, int> m_TargetTypeAcronym =
{
	{"NONE",		0},  //TargetType_None = 0,
	{"LOS",			1},  //TargetType_LineOfSight = 1,
	{"AEPCINRNG",	2},  //TargetType_AEPC_v1 = 2,                 // players in area around caster
	{"GROUPNEAR",	3},  //TargetType_Group_v1 = 3,                // group members around caster
	{"PBAE",		4},  //TargetType_PBAE = 4,                    // area around caster
	{"SINGLE",		5},  //TargetType_Single = 5,                  // current target
	{"SELF",		6},  //TargetType_Self = 6,                    // targets self only
	{"UNKN7",		7},
	{"AREA",		8},  //TargetType_TargetArea = 8,              // radius around target
	{"ANIMAL",		9},  //TargetType_TargetAnimal = 9,
	{"UNDEAD",		10}, //TargetType_TargetUndead = 10,
	{"SUMMONED",	11}, //TargetType_TargetSummoned = 11,
	{"UNKN12",		12},
	{"DRAIN",		13}, //TargetType_TargetDrain = 13,
	{"MYPET",		14}, //TargetType_Pet = 14,                    // caster's pet
	{"CORPSE",		15}, //TargetType_TargetCorpse = 15,
	{"PLANT",		16}, //TargetType_TargetPlant = 16,
	{"GIANT",		17}, //TargetType_TargetGiants = 17,
	{"DRAGON",		18}, //TargetType_TargetDragons = 18,
	{"COLDAIN",		19}, //TargetType_TargetColdain = 19,
	{"AEDRAIN",		20}, //TargetType_TargetAEDrain = 20,
	{"UNKN21",		21},
	{"UNKN22",		22},
	{"UNKN23",		23},
	{"AEUNDEAD",	24}, //TargetType_TargetAEUndead = 24,
	{"AESUMMON",	25}, //TargetType_TargetAESummoned = 25,
	{"UNKN26",		26},
	{"UNKN27",		27},
	{"UNKN28",		28},
	{"UNKN29",		29},
	{"UNKN30",		30},
	{"UNKN31",		31},
	{"HATEINRNG",	32}, //TargetType_HateList = 32,               // all players on hatelist in range
	{"HATEOOR",		33}, //TargetType_HateList_All = 33,           // all players on hatelist regardless of range
	{"CURSED",		34}, //TargetType_TargetCursed = 34,
	{"MURAMITE",	35}, //TargetType_TargetMuramite = 35,
	{"AEPC",		36}, //TargetType_CasterAreaPC = 36,
	{"AENPC",		37}, //TargetType_CasterAreaNPC = 37,
	{"PET",			38}, //TargetType_Pet_v2 = 38,                 // targeted pet
	{"PC",			39}, //TargetType_TargetPC = 39,               // targeted player
	{"AEBENEFIT",	40}, //TargetType_AEPC_v2 = 40,                // area beneficial players
	{"GROUP",		41}, //TargetType_Group_v2 = 41,               // area grouped players
	{"CONE",		42}, //TargetType_DirectionalCone = 42,        // projected cone in front of player
	{"GROUPEDPC",	43}, //TargetType_SingleGrouped = 43,          // single target grouped
	{"BEAM",		44}, //TargetType_Beam = 44,
	{"AEFREE",		45}, //TargetType_FreeTarget = 45,             // player picks a point in space
	{"TARGETOF",	46}, //TargetType_TargetOfTarget = 46,
	{"PETOWNER",	47}, //TargetType_PetOwner = 47,               // cast on pet's owner
	{"UNKN48",		48},
	{"UNKN49",		49},
	{"AEDETRMTL",	50}, //TargetType_AreaDetrimental = 50,        // targets enemies of caster
	{"UNKN51",		51},
	{"BENEFIT",		52}, //TargetType_TargetBeneficial = 52,
};

/* Color codes. From macroquest/docs echo.md
\ab = black
\a-b = black (dark)

\ag = green
\a-g = green (dark)

\am = magenta
\a-m = magenta (dark)

\ao = orange
\a-o = orange (dark)

\ap = purple
\a-p = purple (dark)

\ar = red
\a-r = red (dark)

\at = cyan
\a-t = cyan (dark)

\au = blue
\a-u = blue (dark)

\aw = white
\a-w = white (dark)

\ay = yellow
\a-y = yellow (dark)

\ax = previous color (if no previous \a? this would be the default mq2 color)
*/

std::string eResistTypereversed[] =
{
	"None",
	"Magic",
	"Fire",
	"Cold",
	"Poison",
	"Disease",
	"Chromatic",
	"Prismatic",
	"Physical",
	"Corruption",
};

/*
 No currently built in method to reverse key value enumeration lookup, so did it the old fashioned way.
*/
std::string eEQSPAreversed[] =
{
"SPA_HP",
"SPA_AC",
"SPA_ATTACK_POWER",
"SPA_MOVEMENT_RATE",
"SPA_STR",
"SPA_DEX",
"SPA_AGI",
"SPA_STA",
"SPA_INT",
"SPA_WIS",
"SPA_CHA",
"SPA_HASTE",
"SPA_INVISIBILITY",
"SPA_SEE_INVIS",
"SPA_ENDURING_BREATH",
"SPA_MANA",
"SPA_NPC_FRENZY",
"SPA_NPC_AWARENESS",
"SPA_NPC_AGGRO",
"SPA_NPC_FACTION",
"SPA_BLINDNESS",
"SPA_STUN",
"SPA_CHARM",
"SPA_FEAR",
"SPA_FATIGUE",
"SPA_BIND_AFFINITY",
"SPA_GATE",
"SPA_DISPEL_MAGIC",
"SPA_INVIS_VS_UNDEAD",
"SPA_INVIS_VS_ANIMALS",
"SPA_NPC_AGGRO_RADIUS",
"SPA_ENTHRALL",
"SPA_CREATE_ITEM",
"SPA_SUMMON_PET",
"SPA_CONFUSE",
"SPA_DISEASE",
"SPA_POISON",
"SPA_DETECT_HOSTILE",
"SPA_DETECT_MAGIC",
"SPA_NO_TWINCAST",
"SPA_INVULNERABILITY",
"SPA_BANISH",
"SPA_SHADOW_STEP",
"SPA_BERSERK",
"SPA_LYCANTHROPY",
"SPA_VAMPIRISM",
"SPA_RESIST_FIRE",
"SPA_RESIST_COLD",
"SPA_RESIST_POISON",
"SPA_RESIST_DISEASE",
"SPA_RESIST_MAGIC",
"SPA_DETECT_TRAPS",
"SPA_DETECT_UNDEAD",
"SPA_DETECT_SUMMONED",
"SPA_DETECT_ANIMALS",
"SPA_STONESKIN",
"SPA_TRUE_NORTH",
"SPA_LEVITATION",
"SPA_CHANGE_FORM",
"SPA_DAMAGE_SHIELD",
"SPA_TRANSFER_ITEM",
"SPA_ITEM_LORE",
"SPA_ITEM_IDENTIFY",
"SPA_NPC_WIPE_HATE_LIST",
"SPA_SPIN_STUN",
"SPA_INFRAVISION",
"SPA_ULTRAVISION",
"SPA_EYE_OF_ZOMM",
"SPA_RECLAIM_ENERGY",
"SPA_MAX_HP",
"SPA_CORPSE_BOMB",
"SPA_CREATE_UNDEAD",
"SPA_PRESERVE_CORPSE",
"SPA_BIND_SIGHT",
"SPA_FEIGN_DEATH",
"SPA_VENTRILOQUISM",
"SPA_SENTINEL",
"SPA_LOCATE_CORPSE",
"SPA_SPELL_SHIELD",
"SPA_INSTANT_HP",
"SPA_ENCHANT_LIGHT",
"SPA_RESURRECT",
"SPA_SUMMON_TARGET",
"SPA_PORTAL",
"SPA_HP_NPC_ONLY",
"SPA_MELEE_PROC",
"SPA_NPC_HELP_RADIUS",
"SPA_MAGNIFICATION",
"SPA_EVACUATE",
"SPA_HEIGHT",
"SPA_IGNORE_PET",
"SPA_SUMMON_CORPSE",
"SPA_HATE",
"SPA_WEATHER_CONTROL",
"SPA_FRAGILE",
"SPA_SACRIFICE",
"SPA_SILENCE",
"SPA_MAX_MANA",
"SPA_BARD_HASTE",
"SPA_ROOT",
"SPA_HEALDOT",
"SPA_COMPLETEHEAL",
"SPA_PET_FEARLESS",
"SPA_CALL_PET",
"SPA_TRANSLOCATE",
"SPA_NPC_ANTI_GATE",
"SPA_BEASTLORD_PET",
"SPA_ALTER_PET_LEVEL",
"SPA_FAMILIAR",
"SPA_CREATE_ITEM_IN_BAG",
"SPA_ARCHERY",
"SPA_RESIST_ALL",
"SPA_FIZZLE_SKILL",
"SPA_SUMMON_MOUNT",
"SPA_MODIFY_HATE",
"SPA_CORNUCOPIA",
"SPA_CURSE",
"SPA_HIT_MAGIC",
"SPA_AMPLIFICATION",
"SPA_ATTACK_SPEED_MAX",
"SPA_HEALMOD",
"SPA_IRONMAIDEN",
"SPA_REDUCESKILL",
"SPA_IMMUNITY",
"SPA_FOCUS_DAMAGE_MOD",
"SPA_FOCUS_HEAL_MOD",
"SPA_FOCUS_RESIST_MOD",
"SPA_FOCUS_CAST_TIME_MOD",
"SPA_FOCUS_DURATION_MOD",
"SPA_FOCUS_RANGE_MOD",
"SPA_FOCUS_HATE_MOD",
"SPA_FOCUS_REAGENT_MOD",
"SPA_FOCUS_MANACOST_MOD",
"SPA_FOCUS_STUNTIME_MOD",
"SPA_FOCUS_LEVEL_MAX",
"SPA_FOCUS_RESIST_TYPE",
"SPA_FOCUS_TARGET_TYPE",
"SPA_FOCUS_WHICH_SPA",
"SPA_FOCUS_BENEFICIAL",
"SPA_FOCUS_WHICH_SPELL",
"SPA_FOCUS_DURATION_MIN",
"SPA_FOCUS_INSTANT_ONLY",
"SPA_FOCUS_LEVEL_MIN",
"SPA_FOCUS_CASTTIME_MIN",
"SPA_FOCUS_CASTTIME_MAX",
"SPA_NPC_PORTAL_WARDER_BANISH",
"SPA_PORTAL_LOCATIONS",
"SPA_PERCENT_HEAL",
"SPA_STACKING_BLOCK",
"SPA_STRIP_VIRTUAL_SLOT",
"SPA_DIVINE_INTERVENTION",
"SPA_POCKET_PET",
"SPA_PET_SWARM",
"SPA_HEALTH_BALANCE",
"SPA_CANCEL_NEGATIVE_MAGIC",
"SPA_POP_RESURRECT",
"SPA_MIRROR",
"SPA_FEEDBACK",
"SPA_REFLECT",
"SPA_MODIFY_ALL_STATS",
"SPA_CHANGE_SOBRIETY",
"SPA_SPELL_GUARD",
"SPA_MELEE_GUARD",
"SPA_ABSORB_HIT",
"SPA_OBJECT_SENSE_TRAP",
"SPA_OBJECT_DISARM_TRAP",
"SPA_OBJECT_PICKLOCK",
"SPA_FOCUS_PET",
"SPA_DEFENSIVE",
"SPA_CRITICAL_MELEE",
"SPA_CRITICAL_SPELL",
"SPA_CRIPPLING_BLOW",
"SPA_EVASION",
"SPA_RIPOSTE",
"SPA_DODGE",
"SPA_PARRY",
"SPA_DUAL_WIELD",
"SPA_DOUBLE_ATTACK",
"SPA_MELEE_LIFETAP",
"SPA_PURETONE",
"SPA_SANCTIFICATION",
"SPA_FEARLESS",
"SPA_HUNDRED_HANDS",
"SPA_SKILL_INCREASE_CHANCE",
"SPA_ACCURACY",
"SPA_SKILL_DAMAGE_MOD",
"SPA_MIN_DAMAGE_DONE_MOD",
"SPA_MANA_BALANCE",
"SPA_BLOCK",
"SPA_ENDURANCE",
"SPA_INCREASE_MAX_ENDURANCE",
"SPA_AMNESIA",
"SPA_HATE_OVER_TIME",
"SPA_SKILL_ATTACK",
"SPA_FADE",
"SPA_STUN_RESIST",
"SPA_STRIKETHROUGH1",
"SPA_SKILL_DAMAGE_TAKEN",
"SPA_INSTANT_ENDURANCE",
"SPA_TAUNT",
"SPA_PROC_CHANCE",
"SPA_RANGE_ABILITY",
"SPA_ILLUSION_OTHERS",
"SPA_MASS_GROUP_BUFF",
"SPA_GROUP_FEAR_IMMUNITY",
"SPA_RAMPAGE",
"SPA_AE_TAUNT",
"SPA_FLESH_TO_BONE",
"SPA_PURGE_POISON",
"SPA_CANCEL_BENEFICIAL",
"SPA_SHIELD_CASTER",
"SPA_DESTRUCTIVE_FORCE",
"SPA_FOCUS_FRENZIED_DEVASTATION",
"SPA_PET_PCT_MAX_HP",
"SPA_HP_MAX_HP",
"SPA_PET_PCT_AVOIDANCE",
"SPA_MELEE_ACCURACY",
"SPA_HEADSHOT",
"SPA_PET_CRIT_MELEE",
"SPA_SLAY_UNDEAD",
"SPA_INCREASE_SKILL_DAMAGE",
"SPA_REDUCE_WEIGHT",
"SPA_BLOCK_BEHIND",
"SPA_DOUBLE_RIPOSTE",
"SPA_ADD_RIPOSTE",
"SPA_GIVE_DOUBLE_ATTACK",
"SPA_2H_BASH",
"SPA_REDUCE_SKILL_TIMER",
"SPA_ACROBATICS",
"SPA_CAST_THROUGH_STUN",
"SPA_EXTENDED_SHIELDING",
"SPA_BASH_CHANCE",
"SPA_DIVINE_SAVE",
"SPA_METABOLISM",
"SPA_POISON_MASTERY",
"SPA_FOCUS_CHANNELING",
"SPA_FREE_PET",
"SPA_PET_AFFINITY",
"SPA_PERM_ILLUSION",
"SPA_STONEWALL",
"SPA_STRING_UNBREAKABLE",
"SPA_IMPROVE_RECLAIM_ENERGY",
"SPA_INCREASE_CHANGE_MEMWIPE",
"SPA_ENHANCED_CHARM",
"SPA_ENHANCED_ROOT",
"SPA_TRAP_CIRCUMVENTION",
"SPA_INCREASE_AIR_SUPPLY",
"SPA_INCREASE_MAX_SKILL",
"SPA_EXTRA_SPECIALIZATION",
"SPA_OFFHAND_MIN_WEAPON_DAMAGE",
"SPA_INCREASE_PROC_CHANCE",
"SPA_ENDLESS_QUIVER",
"SPA_BACKSTAB_FRONT",
"SPA_CHAOTIC_STAB",
"SPA_NOSPELL",
"SPA_SHIELDING_DURATION_MOD",
"SPA_SHROUD_OF_STEALTH",
"SPA_GIVE_PET_HOLD",
"SPA_TRIPLE_BACKSTAB",
"SPA_AC_LIMIT_MOD",
"SPA_ADD_INSTRUMENT_MOD",
"SPA_SONG_MOD_CAP",
"SPA_INCREASE_STAT_CAP",
"SPA_TRADESKILL_MASTERY",
"SPA_REDUCE_AA_TIMER",
"SPA_NO_FIZZLE",
"SPA_ADD_2H_ATTACK_CHANCE",
"SPA_ADD_PET_COMMANDS",
"SPA_ALCHEMY_FAIL_RATE",
"SPA_FIRST_AID",
"SPA_EXTEND_SONG_RANGE",
"SPA_BASE_RUN_MOD",
"SPA_INCREASE_CASTING_LEVEL",
"SPA_DOTCRIT",
"SPA_HEALCRIT",
"SPA_MENDCRIT",
"SPA_DUAL_WIELD_AMT",
"SPA_EXTRA_DI_CHANCE",
"SPA_FINISHING_BLOW",
"SPA_FLURRY",
"SPA_PET_FLURRY",
"SPA_PET_FEIGN",
"SPA_INCREASE_BANDAGE_AMT",
"SPA_WU_ATTACK",
"SPA_IMPROVE_LOH",
"SPA_NIMBLE_EVASION",
"SPA_FOCUS_DAMAGE_AMT",
"SPA_FOCUS_DURATION_AMT",
"SPA_ADD_PROC_HIT",
"SPA_DOOM_EFFECT",
"SPA_INCREASE_RUN_SPEED_CAP",
"SPA_PURIFY",
"SPA_STRIKETHROUGH",
"SPA_STUN_RESIST2",
"SPA_SPELL_CRIT_CHANCE",
"SPA_REDUCE_SPECIAL_TIMER",
"SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL",
"SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL",
"SPA_TINY_COMPANION",
"SPA_WAKE_DEAD",
"SPA_DOPPELGANGER",
"SPA_INCREASE_RANGE_DMG",
"SPA_FOCUS_DAMAGE_MOD_CRIT",
"SPA_FOCUS_DAMAGE_AMT_CRIT",
"SPA_SECONDARY_RIPOSTE_MOD",
"SPA_DAMAGE_SHIELD_MOD",
"SPA_WEAK_DEAD_2",
"SPA_APPRAISAL",
"SPA_ZONE_SUSPEND_MINION",
"SPA_TELEPORT_CASTERS_BINDPOINT",
"SPA_FOCUS_REUSE_TIMER",
"SPA_FOCUS_COMBAT_SKILL",
"SPA_OBSERVER",
"SPA_FORAGE_MASTER",
"SPA_IMPROVED_INVIS",
"SPA_IMPROVED_INVIS_UNDEAD",
"SPA_IMPROVED_INVIS_ANIMALS",
"SPA_INCREASE_WORN_HP_REGEN_CAP",
"SPA_INCREASE_WORN_MANA_REGEN_CAP",
"SPA_CRITICAL_HP_REGEN",
"SPA_SHIELD_BLOCK_CHANCE",
"SPA_REDUCE_TARGET_HATE",
"SPA_GATE_STARTING_CITY",
"SPA_DEFENSIVE_PROC",
"SPA_HP_FOR_MANA",
"SPA_NO_BREAK_AE_SNEAK",
"SPA_ADD_SPELL_SLOTS",
"SPA_ADD_BUFF_SLOTS",
"SPA_INCREASE_NEGATIVE_HP_LIMIT",
"SPA_MANA_ABSORB_PCT_DMG",
"SPA_CRIT_ATTACK_MODIFIER",
"SPA_FAIL_ALCHEMY_ITEM_RECOVERY",
"SPA_SUMMON_TO_CORPSE",
"SPA_DOOM_RUNE_EFFECT",
"SPA_NO_MOVE_HP",
"SPA_FOCUSED_IMMUNITY",
"SPA_ILLUSIONARY_TARGET",
"SPA_INCREASE_EXP_MOD",
"SPA_EXPEDIENT_RECOVERY",
"SPA_FOCUS_CASTING_PROC",
"SPA_CHANCE_SPELL",
"SPA_WORN_ATTACK_CAP",
"SPA_NO_PANIC",
"SPA_SPELL_INTERRUPT",
"SPA_ITEM_CHANNELING",
"SPA_ASSASSINATE_MAX_LEVEL",
"SPA_HEADSHOT_MAX_LEVEL",
"SPA_DOUBLE_RANGED_ATTACK",
"SPA_FOCUS_MANA_MIN",
"SPA_INCREASE_SHIELD_DMG",
"SPA_MANABURN",
"SPA_SPAWN_INTERACTIVE_OBJECT",
"SPA_INCREASE_TRAP_COUNT",
"SPA_INCREASE_SOI_COUNT",
"SPA_DEACTIVATE_ALL_TRAPS",
"SPA_LEARN_TRAP",
"SPA_CHANGE_TRIGGER_TYPE",
"SPA_FOCUS_MUTE",
"SPA_INSTANT_MANA",
"SPA_PASSIVE_SENSE_TRAP",
"SPA_PROC_ON_KILL_SHOT",
"SPA_PROC_ON_DEATH",
"SPA_POTION_BELT",
"SPA_BANDOLIER",
"SPA_ADD_TRIPLE_ATTACK_CHANCE",
"SPA_PROC_ON_SPELL_KILL_SHOT",
"SPA_GROUP_SHIELDING",
"SPA_MODIFY_BODY_TYPE",
"SPA_MODIFY_FACTION",
"SPA_CORRUPTION",
"SPA_RESIST_CORRUPTION",
"SPA_SLOW",
"SPA_GRANT_FORAGING",
"SPA_DOOM_ALWAYS",
"SPA_TRIGGER_SPELL",
"SPA_CRIT_DOT_DMG_MOD",
"SPA_FLING",
"SPA_DOOM_ENTITY",
"SPA_RESIST_OTHER_SPA",
"SPA_DIRECTIONAL_TELEPORT",
"SPA_EXPLOSIVE_KNOCKBACK",
"SPA_FLING_TOWARD",
"SPA_SUPPRESSION",
"SPA_FOCUS_CASTING_PROC_NORMALIZED",
"SPA_FLING_AT",
"SPA_FOCUS_WHICH_GROUP",
"SPA_DOOM_DISPELLER",
"SPA_DOOM_DISPELLEE",
"SPA_SUMMON_ALL_CORPSES",
"SPA_REFRESH_SPELL_TIMER",
"SPA_LOCKOUT_SPELL_TIMER",
"SPA_FOCUS_MANA_MAX",
"SPA_FOCUS_HEAL_AMT",
"SPA_FOCUS_HEAL_MOD_BENEFICIAL",
"SPA_FOCUS_HEAL_AMT_BENEFICIAL",
"SPA_FOCUS_HEAL_MOD_CRIT",
"SPA_FOCUS_HEAL_AMT_CRIT",
"SPA_ADD_PET_AC",
"SPA_FOCUS_SWARM_PET_DURATION",
"SPA_FOCUS_TWINCAST_CHANCE",
"SPA_HEALBURN",
"SPA_MANA_IGNITE",
"SPA_ENDURANCE_IGNITE",
"SPA_FOCUS_SPELL_CLASS",
"SPA_FOCUS_SPELL_SUBCLASS",
"SPA_STAFF_BLOCK_CHANCE",
"SPA_DOOM_LIMIT_USE",
"SPA_DOOM_FOCUS_USED",
"SPA_LIMIT_HP",
"SPA_LIMIT_MANA",
"SPA_LIMIT_ENDURANCE",
"SPA_FOCUS_LIMIT_CLASS",
"SPA_FOCUS_LIMIT_RACE",
"SPA_FOCUS_BASE_EFFECTS",
"SPA_FOCUS_LIMIT_SKILL",
"SPA_FOCUS_LIMIT_ITEM_CLASS",
"SPA_AC2",
"SPA_MANA2",
"SPA_FOCUS_INCREASE_SKILL_DMG_2",
"SPA_PROC_EFFECT_2",
"SPA_FOCUS_LIMIT_USE",
"SPA_FOCUS_LIMIT_USE_AMT",
"SPA_FOCUS_LIMIT_USE_MIN",
"SPA_FOCUS_LIMIT_USE_TYPE",
"SPA_GRAVITATE",
"SPA_FLY",
"SPA_ADD_EXTENDED_TARGET_SLOTS",
"SPA_SKILL_PROC",
"SPA_PROC_SKILL_MODIFIER",
"SPA_SKILL_PROC_SUCCESS",
"SPA_POST_EFFECT",
"SPA_POST_EFFECT_DATA",
"SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS",
"SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT",
"SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2",
"SPA_FRAGILE_DEFENSE",
"SPA_FREEZE_BUFF_TIMER",
"SPA_TELEPORT_TO_ANCHOR",
"SPA_TRANSLOCATE_TO_ANCHOR",
"SPA_ASSASSINATE",
"SPA_FINISHING_BLOW_MAX",
"SPA_DISTANCE_REMOVAL",
"SPA_REQUIRE_TARGET_DOOM",
"SPA_REQUIRE_CASTER_DOOM",
"SPA_IMPROVED_TAUNT",
"SPA_ADD_MERC_SLOT",
"SPA_STACKER_A",
"SPA_STACKER_B",
"SPA_STACKER_C",
"SPA_STACKER_D",
"SPA_DOT_GUARD",
"SPA_MELEE_THRESHOLD_GUARD",
"SPA_SPELL_THRESHOLD_GUARD",
"SPA_MELEE_THRESHOLD_DOOM",
"SPA_SPELL_THRESHOLD_DOOM",
"SPA_ADD_HATE_PCT",
"SPA_ADD_HATE_OVER_TIME_PCT",
"SPA_RESOURCE_TAP",
"SPA_FACTION_MOD",
"SPA_SKILL_DAMAGE_MOD_2",
"SPA_OVERRIDE_NOT_FOCUSABLE",
"SPA_FOCUS_DAMAGE_MOD_2",
"SPA_FOCUS_DAMAGE_AMT_2",
"SPA_SHIELD",
"SPA_PC_PET_RAMPAGE",
"SPA_PC_PET_AE_RAMPAGE",
"SPA_PC_PET_FLURRY",
"SPA_DAMAGE_SHIELD_MITIGATION_AMT",
"SPA_DAMAGE_SHIELD_MITIGATION_PCT",
"SPA_CHANCE_BEST_IN_SPELL_GROUP",
"SPA_TRIGGER_BEST_IN_SPELL_GROUP",
"SPA_DOUBLE_MELEE_ATTACKS",
"SPA_AA_BUY_NEXT_RANK",
"SPA_DOUBLE_BACKSTAB_FRONT",
"SPA_PET_MELEE_CRIT_DMG_MOD",
"SPA_TRIGGER_SPELL_NON_ITEM",
"SPA_WEAPON_STANCE",
"SPA_HATELIST_TO_TOP",
"SPA_HATELIST_TO_TAIL",
"SPA_FOCUS_LIMIT_MIN_VALUE",
"SPA_FOCUS_LIMIT_MAX_VALUE",
"SPA_FOCUS_CAST_SPELL_ON_LAND",
"SPA_SKILL_BASE_DAMAGE_MOD",
"SPA_FOCUS_INCOMING_DMG_MOD",
"SPA_FOCUS_INCOMING_DMG_AMT",
"SPA_FOCUS_LIMIT_CASTER_CLASS",
"SPA_FOCUS_LIMIT_SAME_CASTER",
"SPA_EXTEND_TRADESKILL_CAP",
"SPA_DEFENDER_MELEE_FORCE_PCT",
"SPA_WORN_ENDURANCE_REGEN_CAP",
"SPA_FOCUS_MIN_REUSE_TIME",
"SPA_FOCUS_MAX_REUSE_TIME",
"SPA_FOCUS_ENDURANCE_MIN",
"SPA_FOCUS_ENDURANCE_MAX",
"SPA_PET_ADD_ATK",
"SPA_FOCUS_DURATION_MAX",
"SPA_CRIT_MELEE_DMG_MOD_MAX",
"SPA_FOCUS_CAST_PROC_NO_BYPASS",
"SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT",
"SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT",
"SPA_FOCUS_CAST_TIME_MOD2",
"SPA_FOCUS_CAST_TIME_AMT",
"SPA_FEARSTUN",
"SPA_MELEE_DMG_POSITION_MOD",
"SPA_MELEE_DMG_POSITION_AMT",
"SPA_DMG_TAKEN_POSITION_MOD",
"SPA_DMG_TAKEN_POSITION_AMT",
"SPA_AMPLIFY_MOD",
"SPA_AMPLIFY_AMT",
"SPA_HEALTH_TRANSFER",
"SPA_FOCUS_RESIST_INCOMING",
"SPA_FOCUS_TIMER_MIN",
"SPA_PROC_TIMER_MOD",
"SPA_MANA_MAX",
"SPA_ENDURANCE_MAX",
"SPA_AC_AVOIDANCE_MAX",
"SPA_AC_MITIGATION_MAX",
"SPA_ATTACK_OFFENSE_MAX",
"SPA_ATTACK_ACCURACY_MAX",
"SPA_LUCK_AMT",
"SPA_LUCK_PCT",
"SPA_ENDURANCE_ABSORB_PCT_DMG",
"SPA_INSTANT_MANA_PCT",
"SPA_INSTANT_ENDURANCE_PCT",
"SPA_DURATION_HP_PCT",
"SPA_DURATION_MANA_PCT",
"SPA_DURATION_ENDURANCE_PCT",
};

enum class eEQSkills
{
	SKILL_1H_BLUNT,                // 0
	SKILL_1H_SLASHING,             // 1
	SKILL_2H_BLUNT,                // 2
	SKILL_2H_SLASHING,             // 3
	SKILL_ABJURATION,              // 4
	SKILL_ALTERATION,              // 5
	SKILL_APPLY_POISON,            // 6
	SKILL_ARCHERY,                 // 7
	SKILL_BACKSTAB,                // 8
	SKILL_BIND_WOUND,              // 9
	SKILL_BASH,                    // 10
	SKILL_BLOCK,                   // 11
	SKILL_BRASS_INSTRUMENTS,       // 12
	SKILL_CHANNELING,              // 13
	SKILL_CONJURATION,             // 14
	SKILL_DEFENSE,                 // 15
	SKILL_DISARM,                  // 16
	SKILL_DISARM_TRAPS,            // 17
	SKILL_DIVINATION,              // 18
	SKILL_DODGE,                   // 19
	SKILL_DOUBLE_ATTACK,           // 20
	SKILL_DRAGON_PUNCH,            // 21
	SKILL_DUAL_WIELD,              // 22
	SKILL_EAGLE_STRIKE,            // 23
	SKILL_EVOCATION,               // 24
	SKILL_FEIGN_DEATH,             // 25
	SKILL_FLYING_KICK,             // 26
	SKILL_FORAGE,                  // 27
	SKILL_HAND_TO_HAND,            // 28
	SKILL_HIDE,                    // 29
	SKILL_KICK,                    // 30
	SKILL_MEDITATE,                // 31
	SKILL_MEND,                    // 32
	SKILL_OFFENSE,                 // 33
	SKILL_PARRY,                   // 34
	SKILL_PICK_LOCK,               // 35
	SKILL_1H_PIERCING,             // 36
	SKILL_RIPOSTE,                 // 37
	SKILL_ROUND_KICK,              // 38
	SKILL_SAFE_FALL,               // 39
	SKILL_SENSE_HEADING,           // 40
	SKILL_SINGING,                 // 41
	SKILL_SNEAK,                   // 42 //anything above 100 means a successrate of 100%
	SKILL_SPECIALIZE_ABJURE,       // 43
	SKILL_SPECIALIZE_ALTERATION,   // 44
	SKILL_SPECIALIZE_CONJURATION,  // 45
	SKILL_SPECIALIZE_DIVINATION,   // 46
	SKILL_SPECIALIZE_EVOCATION,    // 47
	SKILL_PICK_POCKETS,            // 48
	SKILL_STRINGED_INSTRUMENTS,    // 49
	SKILL_SWIMMING,                // 50
	SKILL_THROWING,                // 51
	SKILL_TIGER_CLAW,              // 52
	SKILL_TRACKING,                // 53
	SKILL_WIND_INSTRUMENTS,        // 54
	SKILL_FISHING,                 // 55
	SKILL_MAKE_POISON,             // 56
	SKILL_TINKERING,               // 57
	SKILL_RESEARCH,                // 58
	SKILL_ALCHEMY,                 // 59
	SKILL_BAKING,                  // 60
	SKILL_TAILORING,               // 61
	SKILL_SENSE_TRAPS,             // 62
	SKILL_BLACKSMITHING,           // 63
	SKILL_FLETCHING,               // 64
	SKILL_BREWING,                 // 65
	SKILL_ALCOHOL_TOLERANCE,       // 66
	SKILL_BEGGING,                 // 67
	SKILL_JEWELRY_MAKING,          // 68
	SKILL_POTTERY,                 // 69
	SKILL_PERCUSSION_INSTRUMENTS,  // 70
	SKILL_INTIMIDATION,            // 71
	SKILL_BERSERKING,              // 72
	SKILL_TAUNT,                   // 73
	SKILL_FRENZY,                  // 74
	SKILL_REMOVE_TRAP,             // 75
	SKILL_TRIPLE_ATTACK,           // 76
	SKILL_2H_PIERCING,             // 77
	SKILL_78,                      // 78
	SKILL_79,                      // 79
	SKILL_80,                      // 80
	SKILL_81,                      // 81
	SKILL_82,                      // 82
	SKILL_83,                      // 83
	SKILL_84,                      // 84
	SKILL_85,                      // 85
	SKILL_86,                      // 86
	SKILL_87,                      // 87
	SKILL_88,                      // 88
	SKILL_89,                      // 89
	SKILL_90,                      // 90
	SKILL_91,                      // 91
	SKILL_92,                      // 92
	SKILL_93,                      // 93
	SKILL_94,                      // 94
	SKILL_95,                      // 95
	SKILL_96,                      // 96
	SKILL_97,                      // 97
	SKILL_98,                      // 98
	SKILL_99,                      // 99
	SKILL_100,                     // 100
	SKILL_101,                     // 101
	SKILL_102,                     // 102
	SKILL_103,                     // 103
	SKILL_104,                     // 104
	SKILL_HARM_TOUCH,              // 105
	SKILL_106,                     // 106
	SKILL_LAY_HANDS,               // 107
	SKILL_108,                     // 108
	SKILL_109,                     // 109
	SKILL_110,                     // 110
	SKILL_SLAM,                    // 111
	SKILL_112,                     // 112
	SKILL_113,                     // 113
	SKILL_INSPECT,                 // 114
	SKILL_OPEN,                    // 115
	SKILL_REVEAL_TRAP,             // 116
	SKILL_117,                     // 117
	SKILL_118,                     // 118
	SKILL_119,                     // 119
	SKILL_120,                     // 120
	SKILL_121,                     // 121
	SKILL_122,                     // 122
	SKILL_123,                     // 123
	SKILL_124,                     // 124
	SKILL_125,                     // 125
	SKILL_126,                     // 126
	SKILL_127,                     // 127 this should be last one
	SKILL_128,                     // 128 here for compatibility
	SKILL_129,                     // 129 here for compatibility
	SKILL_130,                     // 130 here for compatibility
	SKILL_131,                     // 131 here for compatibility
	SKILL_THROW_STONE,             // 132 here for compatibility 
};

/*
	Lists of Categories, SPA, Spell members from Spells.h, MQ2Spells.cpp
*/

//This is just a list of spell members to consider for using for searching spells.
/*
void NothingButAList(PSPELL pSpell) {
	pSpell->ActorTagId;
	pSpell->AEDuration;
	pSpell->AERange;
	pSpell->AffectInanimate;
	pSpell->AIValidTargets;
	pSpell->AnimVariation;
	pSpell->Autocast;
	pSpell->BaseEffectsFocusCap;
	pSpell->BaseEffectsFocusOffset;
	pSpell->BaseEffectsFocusSlope;
	pSpell->bStacksWithDiscs;
	pSpell->BypassRegenCheck;
	pSpell->CalcIndex;
	pSpell->CanCastInCombat;
	pSpell->CanCastOutOfCombat;
	pSpell->CancelOnSit;
	pSpell->CanMGB;
	pSpell->CannotBeScribed;
	pSpell->CastDifficulty;
	pSpell->CasterRequirementID;
	pSpell->CastingAnim;
	pSpell->CastNotStanding;
	pSpell->CastTime;
	pSpell->Category;
	pSpell->ClassLevel;  //array
	pSpell->ConeEndAngle;
	pSpell->ConeStartAngle;
	pSpell->CountdownHeld;
	pSpell->CRC32Marker;
	pSpell->CritChanceOverride;
	pSpell->Deletable;
	pSpell->DescriptionIndex;
	pSpell->Deity;
	pSpell->DistanceMod;
	pSpell->DistanceModEnd;
	pSpell->DistanceModStart;
	pSpell->DurationCap;
	pSpell->DurationParticleEffect;
	pSpell->DurationType;
	pSpell->DurationWindow;
	pSpell->EnduranceCost;
	pSpell->EnduranceValue;
	pSpell->EnduranceUpkeep;
	pSpell->Environment;
	pSpell->Extra; // array
	pSpell->Feedbackable;
	pSpell->HateGenerated;
	pSpell->HateMod;
	pSpell->HitCount;
	pSpell->HitCountType;
	pSpell->ID;
	pSpell->IsSkill;
	pSpell->LightType;
	pSpell->ManaCost;
	pSpell->MaxResist;
	pSpell->MaxSpreadTime;
	pSpell->MaxTargets;
	pSpell->MinRange;
	pSpell->MinResist;
	pSpell->MinSpreadTime;
	pSpell->Name;
	pSpell->NoBuffBlock;
	pSpell->NoDispell;
	pSpell->NoExpendReagent; //array
	pSpell->NoHate;
	pSpell->NoHealDamageItemMod;
	pSpell->NoNPCLOS;
	pSpell->NoOverwrite;
	pSpell->NoPartialSave;
	pSpell->NoRemove;
	pSpell->NoResist;
	pSpell->NoStripOnDeath;
	pSpell->NotFocusable;
	pSpell->NotStackableDot;
	pSpell->NPCChanceofKnowingSpell;
	pSpell->NPCMemCategory;
	pSpell->NPCUsefulness;
	pSpell->NumEffects;
	pSpell->OnlyDuringFastRegen;
	pSpell->PCNPCOnlyFlag;
	pSpell->PushBack;
	pSpell->PushUp;
	pSpell->PvPCalc;
	pSpell->PvPDuration;
	pSpell->PvPDurationCap;
	pSpell->PvPResistBase;
	pSpell->PvPResistCap;
	pSpell->Range;
	pSpell->ReagentCount; //array
	pSpell->ReagentID; //array
	pSpell->RecastTime;
	pSpell->RecoveryTime;
	pSpell->Reflectable;
	pSpell->Resist;
	pSpell->ResistAdj;
	pSpell->ResistCap;
	pSpell->ResistPerLevel;
	pSpell->ReuseTimerIndex;
	pSpell->Scribable;
	pSpell->ShowWearOffMessage;
	pSpell->Skill;
	pSpell->SneakAttack;
	pSpell->spaindex;
	pSpell->SpellAnim;
	pSpell->SpellClass;
	pSpell->SpellGroup;
	pSpell->SpellIcon;
	pSpell->SpellRank;
	pSpell->SpellRecourseType;
	pSpell->SpellReqAssociationID;
	pSpell->SpellSubClass;
	pSpell->SpellSubGroup;
	pSpell->SpellType;
	pSpell->SpreadRadius;
	pSpell->StacksWithSelf;
	pSpell->Subcategory;
	pSpell->Subcategory2;
	pSpell->TargetAnim;
	pSpell->TargetType;
	pSpell->TimeOfDay;
	pSpell->TravelType;
	pSpell->Uninterruptable;
	pSpell->Unknown0x02C;
	pSpell->UsesPersistentParticles;
	pSpell->ZoneType;
}
*/

std::string CategoryNameLookup[] =
{
	"None"                , // 0
	"Aegolism"            , // 1
	"Agility"             , // 2
	"Alliance"            , // 3
	"Animal"              , // 4
	"Antonica"            , // 5
	"Armor Class"         , // 6
	"Attack"              , // 7
	"Bane"                , // 8
	"Blind"               , // 9
	"Block"               , // 10
	"Calm"                , // 11
	"Charisma"            , // 12
	"Charm"               , // 13
	"Cold"                , // 14
	"Combat Abilities"    , // 15
	"Combat Innates"      , // 16
	"Conversions"         , // 17
	"Create Item"         , // 18
	"Cure"                , // 19
	"Damage Over Time"    , // 20
	"Damage Shield"       , // 21
	"Defensive"           , // 22
	"Destroy"             , // 23
	"Dexterity"           , // 24
	"Direct Damage"       , // 25
	"Disarm Traps"        , // 26
	"Disciplines"         , // 27
	"Discord"             , // 28
	"Disease"             , // 29
	"Disempowering"       , // 30
	"Dispel"              , // 31
	"Duration Heals"      , // 32
	"Duration Tap"        , // 33
	"Enchant Metal"       , // 34
	"Enthrall"            , // 35
	"Faydwer"             , // 36
	"Fear"                , // 37
	"Fire"                , // 38
	"Fizzle Rate"         , // 39
	"Fumble"              , // 40
	"Haste"               , // 41
	"Heals"               , // 42
	"Health"              , // 43
	"Health/Mana"         , // 44
	"HP Buffs"            , // 45
	"HP type one"         , // 46
	"HP type two"         , // 47
	"Illusion: Other"     , // 48
	"Illusion: Adventurer", // 49
	"Imbue Gem"           , // 50
	"Invisibility"        , // 51
	"Invulnerability"     , // 52
	"Jolt"                , // 53
	"Kunark"              , // 54
	"Levitate"            , // 55
	"Life Flow"           , // 56
	"Luclin"              , // 57
	"Magic"               , // 58
	"Mana"                , // 59
	"Mana Drain"          , // 60
	"Mana Flow"           , // 61
	"Melee Guard"         , // 62
	"Memory Blur"         , // 63
	"Misc"                , // 64
	"Movement"            , // 65
	"Objects"             , // 66
	"Odus"                , // 67
	"Offensive"           , // 68
	"Pet"                 , // 69
	"Pet Haste"           , // 70
	"Pet Misc Buffs"      , // 0
	"Physical"            , // 0
	"Picklock"            , // 0
	"Plant"               , // 0
	"Poison"              , // 0
	"Power Tap"           , // 0
	"Quick Heal"          , // 0
	"Reflection"          , // 0
	"Regen"               , // 0
	"Resist Buff"         , // 0
	"Resist Debuffs"      , // 0
	"Resurrection"        , // 0
	"Root"                , // 0
	"Rune"                , // 0
	"Sense Trap"          , // 0
	"Shadowstep"          , // 0
	"Shielding"           , // 0
	"Slow"                , // 0
	"Snare"               , // 0
	"Special"             , // 0
	"Spell Focus"         , // 0
	"Spell Guard"         , // 0
	"Spellshield"         , // 0
	"Stamina"             , // 0
	"Statistic Buffs"     , // 0
	"Strength"            , // 0
	"Stun"                , // 0
	"Sum: Air"            , // 0
	"Sum: Animation"      , // 0
	"Sum: Earth"          , // 0
	"Sum: Familiar"       , // 0
	"Sum: Fire"           , // 0
	"Sum: Undead"         , // 0
	"Sum: Warder"         , // 0
	"Sum: Water"          , // 0
	"Summon Armor"        , // 0
	"Summon Focus"        , // 0
	"Summon Food/Water"   , // 0
	"Summon Utility"      , // 0
	"Summon Weapon"       , // 0
	"Summoned"            , // 0
	"Symbol"              , // 0
	"Taelosia"            , // 0
	"Taps"                , // 0
	"Techniques"          , // 0
	"The Planes"          , // 0
	"Timer 1"             , // 0
	"Timer 2"             , // 0
	"Timer 3"             , // 0
	"Timer 4"             , // 0
	"Timer 5"             , // 0
	"Timer 6"             , // 0
	"Transport"           , // 0
	"Undead"              , // 0
	"Utility Beneficial"  , // 0
	"Utility Detrimental" , // 0
	"Velious"             , // 0
	"Visages"             , // 0
	"Vision"              , // 0
	"Wisdom/Intelligence" , // 0
	"Traps"               , // 0
	"Auras"               , // 0
	"Endurance"           , // 0
	"Serpent's Spine"     , // 0
	"Corruption"          , // 0
	"Learning"            , // 0
	"Chromatic"           , // 0
	"Prismatic"           , // 0
	"Sum: Swarm"          , // 0
	"Delayed"             , // 0
	"Temporary"           , // 0
	"Twincast"            , // 0
	"Sum: Bodyguard"      , // 0
	"Humanoid"            , // 0
	"Haste/Spell Focus"   , // 0
	"Timer 7"             , // 0
	"Timer 8"             , // 0
	"Timer 9"             , // 0
	"Timer 10"            , // 0
	"Timer 11"            , // 0
	"Timer 12"            , // 0
	"Hatred"              , // 0
	"Fast"                , // 0
	"Illusion: Special"   , // 0
	"Timer 13"            , // 0
	"Timer 14"            , // 0
	"Timer 15"            , // 0
	"Timer 16"            , // 0
	"Timer 17"            , // 0
	"Timer 18"            , // 0
	"Timer 19"            , // 0
	"Timer 20"            , // 0
	"Alaris"              , // 0
	"Combination"         , // 0
	"Independent"         , // 0
	"Skill Attacks"       , // 0
	"Incoming"            , // 0
	"Curse"               , // 0
	"Timer 21"            , // 0
	"Timer 22"            , // 0
	"Timer 23"            , // 0
	"Timer 24"            , // 0
	"Timer 25"            , // 0
	"Drunkenness"         , // 0
	"Throwing"            , // 0
	"Melee Damage"        , // 0
};

/* Categories and Subcategories use this list.

Example: You want an Earth Pet, you first use the lookup tool to navigate
		 to Pet, then Sum: Earth. To do it here, your query would look like:

         if (pSpell->Category != eEQSPELLCAT::SPELLCAT_PET) continue;
		 if (pSpell->Subcategory != eEQSPELLCAT::SPELLCAT_SUM_EARTH) continue;

enum eEQSPELLCAT
{
	SPELLCAT_AEGOLISM = 1,
	SPELLCAT_AGILITY = 2,
	SPELLCAT_ALLIANCE = 3,
	SPELLCAT_ANIMAL = 4,
	SPELLCAT_ANTONICA = 5,
	SPELLCAT_ARMOR_CLASS = 6,
	SPELLCAT_ATTACK = 7,
	SPELLCAT_BANE = 8,
	SPELLCAT_BLIND = 9,
	SPELLCAT_BLOCK = 10,
	SPELLCAT_CALM = 11,
	SPELLCAT_CHARISMA = 12,
	SPELLCAT_CHARM = 13,
	SPELLCAT_COLD = 14,
	SPELLCAT_COMBAT_ABILITIES = 15,
	SPELLCAT_COMBAT_INNATES = 16,
	SPELLCAT_CONVERSIONS = 17,
	SPELLCAT_CREATE_ITEM = 18,
	SPELLCAT_CURE = 19,
	SPELLCAT_DAMAGE_OVER_TIME = 20,
	SPELLCAT_DAMAGE_SHIELD = 21,
	SPELLCAT_DEFENSIVE = 22,
	SPELLCAT_DESTROY = 23,
	SPELLCAT_DEXTERITY = 24,
	SPELLCAT_DIRECT_DAMAGE = 25,
	SPELLCAT_DISARM_TRAPS = 26,
	SPELLCAT_DISCIPLINES = 27,
	SPELLCAT_DISCORD = 28,
	SPELLCAT_DISEASE = 29,
	SPELLCAT_DISEMPOWERING = 30,
	SPELLCAT_DISPEL = 31,
	SPELLCAT_DURATION_HEALS = 32,
	SPELLCAT_DURATION_TAP = 33,
	SPELLCAT_ENCHANT_METAL = 34,
	SPELLCAT_ENTHRALL = 35,
	SPELLCAT_FAYDWER = 36,
	SPELLCAT_FEAR = 37,
	SPELLCAT_FIRE = 38,
	SPELLCAT_FIZZLE_RATE = 39,
	SPELLCAT_FUMBLE = 40,
	SPELLCAT_HASTE = 41,
	SPELLCAT_HEALS = 42,
	SPELLCAT_HEALTH = 43,
	SPELLCAT_HEALTH_MANA = 44,
	SPELLCAT_HP_BUFFS = 45,
	SPELLCAT_HP_TYPE_ONE = 46,
	SPELLCAT_HP_TYPE_TWO = 47,
	SPELLCAT_ILLUSION_OTHER = 48,
	SPELLCAT_ILLUSION_ADVENTURER = 49,
	SPELLCAT_IMBUE_GEM = 50,
	SPELLCAT_INVISIBILITY = 51,
	SPELLCAT_INVULNERABILITY = 52,
	SPELLCAT_JOLT = 53,
	SPELLCAT_KUNARK = 54,
	SPELLCAT_LEVITATE = 55,
	SPELLCAT_LIFE_FLOW = 56,
	SPELLCAT_LUCLIN = 57,
	SPELLCAT_MAGIC = 58,
	SPELLCAT_MANA = 59,
	SPELLCAT_MANA_DRAIN = 60,
	SPELLCAT_MANA_FLOW = 61,
	SPELLCAT_MELEE_GUARD = 62,
	SPELLCAT_MEMORY_BLUR = 63,
	SPELLCAT_MISC = 64,
	SPELLCAT_MOVEMENT = 65,
	SPELLCAT_OBJECTS = 66,
	SPELLCAT_ODUS = 67,
	SPELLCAT_OFFENSIVE = 68,
	SPELLCAT_PET = 69,
	SPELLCAT_PET_HASTE = 70,
	SPELLCAT_PET_MISC_BUFFS = 71,
	SPELLCAT_PHYSICAL = 72,
	SPELLCAT_PICKLOCK = 73,
	SPELLCAT_PLANT = 74,
	SPELLCAT_POISON = 75,
	SPELLCAT_POWER_TAP = 76,
	SPELLCAT_QUICK_HEAL = 77,
	SPELLCAT_REFLECTION = 78,
	SPELLCAT_REGEN = 79,
	SPELLCAT_RESIST_BUFF = 80,
	SPELLCAT_RESIST_DEBUFFS = 81,
	SPELLCAT_RESURRECTION = 82,
	SPELLCAT_ROOT = 83,
	SPELLCAT_RUNE = 84,
	SPELLCAT_SENSE_TRAP = 85,
	SPELLCAT_SHADOWSTEP = 86,
	SPELLCAT_SHIELDING = 87,
	SPELLCAT_SLOW = 88,
	SPELLCAT_SNARE = 89,
	SPELLCAT_SPECIAL = 90,
	SPELLCAT_SPELL_FOCUS = 91,
	SPELLCAT_SPELL_GUARD = 92,
	SPELLCAT_SPELLSHIELD = 93,
	SPELLCAT_STAMINA = 94,
	SPELLCAT_STATISTIC_BUFFS = 95,
	SPELLCAT_STRENGTH = 96,
	SPELLCAT_STUN = 97,
	SPELLCAT_SUM_AIR = 98,
	SPELLCAT_SUM_ANIMATION = 99,
	SPELLCAT_SUM_EARTH = 100,
	SPELLCAT_SUM_FAMILIAR = 101,
	SPELLCAT_SUM_FIRE = 102,
	SPELLCAT_SUM_UNDEAD = 103,
	SPELLCAT_SUM_WARDER = 104,
	SPELLCAT_SUM_WATER = 105,
	SPELLCAT_SUMMON_ARMOR = 106,
	SPELLCAT_SUMMON_FOCUS = 107,
	SPELLCAT_SUMMON_FOOD_WATER = 108,
	SPELLCAT_SUMMON_UTILITY = 109,
	SPELLCAT_SUMMON_WEAPON = 110,
	SPELLCAT_SUMMONED = 111,
	SPELLCAT_SYMBOL = 112,
	SPELLCAT_TAELOSIA = 113,
	SPELLCAT_TAPS = 114,
	SPELLCAT_TECHNIQUES = 115,
	SPELLCAT_THE_PLANES = 116,
	SPELLCAT_TIMER_1 = 117,
	SPELLCAT_TIMER_2 = 118,
	SPELLCAT_TIMER_3 = 119,
	SPELLCAT_TIMER_4 = 120,
	SPELLCAT_TIMER_5 = 121,
	SPELLCAT_TIMER_6 = 122,
	SPELLCAT_TRANSPORT = 123,
	SPELLCAT_UNDEAD = 124,
	SPELLCAT_UTILITY_BENEFICIAL = 125,
	SPELLCAT_UTILITY_DETRIMENTAL = 126,
	SPELLCAT_VELIOUS = 127,
	SPELLCAT_VISAGES = 128,
	SPELLCAT_VISION = 129,
	SPELLCAT_WISDOM_INTELLIGENCE = 130,
	SPELLCAT_TRAPS = 131,
	SPELLCAT_AURAS = 132,
	SPELLCAT_ENDURANCE = 133,
	SPELLCAT_SERPENTS_SPINE = 134,
	SPELLCAT_CORRUPTION = 135,
	SPELLCAT_LEARNING = 136,
	SPELLCAT_CHROMATIC = 137,
	SPELLCAT_PRISMATIC = 138,
	SPELLCAT_SUM_SWARM = 139,
	SPELLCAT_DELAYED = 140,
	SPELLCAT_TEMPORARY = 141,
	SPELLCAT_TWINCAST = 142,
	SPELLCAT_SUM_BODYGUARD = 143,
	SPELLCAT_HUMANOID = 144,
	SPELLCAT_HASTE_SPELL_FOCUS = 145,
	SPELLCAT_TIMER_7 = 146,
	SPELLCAT_TIMER_8 = 147,
	SPELLCAT_TIMER_9 = 148,
	SPELLCAT_TIMER_10 = 149,
	SPELLCAT_TIMER_11 = 150,
	SPELLCAT_TIMER_12 = 151,
	SPELLCAT_HATRED = 152,
	SPELLCAT_FAST = 153,
	SPELLCAT_ILLUSION_SPECIAL = 154,
	SPELLCAT_TIMER_13 = 155,
	SPELLCAT_TIMER_14 = 156,
	SPELLCAT_TIMER_15 = 157,
	SPELLCAT_TIMER_16 = 158,
	SPELLCAT_TIMER_17 = 159,
	SPELLCAT_TIMER_18 = 160,
	SPELLCAT_TIMER_19 = 161,
	SPELLCAT_TIMER_20 = 162,
	SPELLCAT_ALARIS = 163,
	SPELLCAT_COMBINATION = 164,
	SPELLCAT_INDEPENDENT = 165,
	SPELLCAT_SKILL_ATTACKS = 166,
	SPELLCAT_INCOMING = 167,
	SPELLCAT_CURSE = 168,
	SPELLCAT_TIMER_21 = 169,
	SPELLCAT_TIMER_22 = 170,
	SPELLCAT_TIMER_23 = 171,
	SPELLCAT_TIMER_24 = 172,
	SPELLCAT_TIMER_25 = 173,
	SPELLCAT_DRUNKENNESS = 174,
	SPELLCAT_THROWING = 175,
	SPELLCAT_MELEE_DAMAGE = 176
};

*/

/* From main/MQ2Spells.cpp 12/28/2021

static const ci_unordered::map<std::string_view, eEQSPELLCAT> s_spellCatLookup = {
{ "Aegolism"            , SPELLCAT_AEGOLISM },
{ "Agility"             , SPELLCAT_AGILITY },
{ "Alliance"            , SPELLCAT_ALLIANCE },
{ "Animal"              , SPELLCAT_ANIMAL },
{ "Antonica"            , SPELLCAT_ANTONICA },
{ "Armor Class"         , SPELLCAT_ARMOR_CLASS },
{ "Attack"              , SPELLCAT_ATTACK },
{ "Bane"                , SPELLCAT_BANE },
{ "Blind"               , SPELLCAT_BLIND },
{ "Block"               , SPELLCAT_BLOCK },
{ "Calm"                , SPELLCAT_CALM },
{ "Charisma"            , SPELLCAT_CHARISMA },
{ "Charm"               , SPELLCAT_CHARM },
{ "Cold"                , SPELLCAT_COLD },
{ "Combat Abilities"    , SPELLCAT_COMBAT_ABILITIES },
{ "Combat Innates"      , SPELLCAT_COMBAT_INNATES },
{ "Conversions"         , SPELLCAT_CONVERSIONS },
{ "Create Item"         , SPELLCAT_CREATE_ITEM },
{ "Cure"                , SPELLCAT_CURE },
{ "Damage Over Time"    , SPELLCAT_DAMAGE_OVER_TIME },
{ "Damage Shield"       , SPELLCAT_DAMAGE_SHIELD },
{ "Defensive"           , SPELLCAT_DEFENSIVE },
{ "Destroy"             , SPELLCAT_DESTROY },
{ "Dexterity"           , SPELLCAT_DEXTERITY },
{ "Direct Damage"       , SPELLCAT_DIRECT_DAMAGE },
{ "Disarm Traps"        , SPELLCAT_DISARM_TRAPS },
{ "Disciplines"         , SPELLCAT_DISCIPLINES },
{ "Discord"             , SPELLCAT_DISCORD },
{ "Disease"             , SPELLCAT_DISEASE },
{ "Disempowering"       , SPELLCAT_DISEMPOWERING },
{ "Dispel"              , SPELLCAT_DISPEL },
{ "Duration Heals"      , SPELLCAT_DURATION_HEALS },
{ "Duration Tap"        , SPELLCAT_DURATION_TAP },
{ "Enchant Metal"       , SPELLCAT_ENCHANT_METAL },
{ "Enthrall"            , SPELLCAT_ENTHRALL },
{ "Faydwer"             , SPELLCAT_FAYDWER },
{ "Fear"                , SPELLCAT_FEAR },
{ "Fire"                , SPELLCAT_FIRE },
{ "Fizzle Rate"         , SPELLCAT_FIZZLE_RATE },
{ "Fumble"              , SPELLCAT_FUMBLE },
{ "Haste"               , SPELLCAT_HASTE },
{ "Heals"               , SPELLCAT_HEALS },
{ "Health"              , SPELLCAT_HEALTH },
{ "Health/Mana"         , SPELLCAT_HEALTH_MANA },
{ "HP Buffs"            , SPELLCAT_HP_BUFFS },
{ "HP type one"         , SPELLCAT_HP_TYPE_ONE },
{ "HP type two"         , SPELLCAT_HP_TYPE_TWO },
{ "Illusion: Other"     , SPELLCAT_ILLUSION_OTHER },
{ "Illusion: Adventurer", SPELLCAT_ILLUSION_ADVENTURER },
{ "Imbue Gem"           , SPELLCAT_IMBUE_GEM },
{ "Invisibility"        , SPELLCAT_INVISIBILITY },
{ "Invulnerability"     , SPELLCAT_INVULNERABILITY },
{ "Jolt"                , SPELLCAT_JOLT },
{ "Kunark"              , SPELLCAT_KUNARK },
{ "Levitate"            , SPELLCAT_LEVITATE },
{ "Life Flow"           , SPELLCAT_LIFE_FLOW },
{ "Luclin"              , SPELLCAT_LUCLIN },
{ "Magic"               , SPELLCAT_MAGIC },
{ "Mana"                , SPELLCAT_MANA },
{ "Mana Drain"          , SPELLCAT_MANA_DRAIN },
{ "Mana Flow"           , SPELLCAT_MANA_FLOW },
{ "Melee Guard"         , SPELLCAT_MELEE_GUARD },
{ "Memory Blur"         , SPELLCAT_MEMORY_BLUR },
{ "Misc"                , SPELLCAT_MISC },
{ "Movement"            , SPELLCAT_MOVEMENT },
{ "Objects"             , SPELLCAT_OBJECTS },
{ "Odus"                , SPELLCAT_ODUS },
{ "Offensive"           , SPELLCAT_OFFENSIVE },
{ "Pet"                 , SPELLCAT_PET },
{ "Pet Haste"           , SPELLCAT_PET_HASTE },
{ "Pet Misc Buffs"      , SPELLCAT_PET_MISC_BUFFS },
{ "Physical"            , SPELLCAT_PHYSICAL },
{ "Picklock"            , SPELLCAT_PICKLOCK },
{ "Plant"               , SPELLCAT_PLANT },
{ "Poison"              , SPELLCAT_POISON },
{ "Power Tap"           , SPELLCAT_POWER_TAP },
{ "Quick Heal"          , SPELLCAT_QUICK_HEAL },
{ "Reflection"          , SPELLCAT_REFLECTION },
{ "Regen"               , SPELLCAT_REGEN },
{ "Resist Buff"         , SPELLCAT_RESIST_BUFF },
{ "Resist Debuffs"      , SPELLCAT_RESIST_DEBUFFS },
{ "Resurrection"        , SPELLCAT_RESURRECTION },
{ "Root"                , SPELLCAT_ROOT },
{ "Rune"                , SPELLCAT_RUNE },
{ "Sense Trap"          , SPELLCAT_SENSE_TRAP },
{ "Shadowstep"          , SPELLCAT_SHADOWSTEP },
{ "Shielding"           , SPELLCAT_SHIELDING },
{ "Slow"                , SPELLCAT_SLOW },
{ "Snare"               , SPELLCAT_SNARE },
{ "Special"             , SPELLCAT_SPECIAL },
{ "Spell Focus"         , SPELLCAT_SPELL_FOCUS },
{ "Spell Guard"         , SPELLCAT_SPELL_GUARD },
{ "Spellshield"         , SPELLCAT_SPELLSHIELD },
{ "Stamina"             , SPELLCAT_STAMINA },
{ "Statistic Buffs"     , SPELLCAT_STATISTIC_BUFFS },
{ "Strength"            , SPELLCAT_STRENGTH },
{ "Stun"                , SPELLCAT_STUN },
{ "Sum: Air"            , SPELLCAT_SUM_AIR },
{ "Sum: Animation"      , SPELLCAT_SUM_ANIMATION },
{ "Sum: Earth"          , SPELLCAT_SUM_EARTH },
{ "Sum: Familiar"       , SPELLCAT_SUM_FAMILIAR },
{ "Sum: Fire"           , SPELLCAT_SUM_FIRE },
{ "Sum: Undead"         , SPELLCAT_SUM_UNDEAD },
{ "Sum: Warder"         , SPELLCAT_SUM_WARDER },
{ "Sum: Water"          , SPELLCAT_SUM_WATER },
{ "Summon Armor"        , SPELLCAT_SUMMON_ARMOR },
{ "Summon Focus"        , SPELLCAT_SUMMON_FOCUS },
{ "Summon Food/Water"   , SPELLCAT_SUMMON_FOOD_WATER },
{ "Summon Utility"      , SPELLCAT_SUMMON_UTILITY },
{ "Summon Weapon"       , SPELLCAT_SUMMON_WEAPON },
{ "Summoned"            , SPELLCAT_SUMMONED },
{ "Symbol"              , SPELLCAT_SYMBOL },
{ "Taelosia"            , SPELLCAT_TAELOSIA },
{ "Taps"                , SPELLCAT_TAPS },
{ "Techniques"          , SPELLCAT_TECHNIQUES },
{ "The Planes"          , SPELLCAT_THE_PLANES },
{ "Timer 1"             , SPELLCAT_TIMER_1 },
{ "Timer 2"             , SPELLCAT_TIMER_2 },
{ "Timer 3"             , SPELLCAT_TIMER_3 },
{ "Timer 4"             , SPELLCAT_TIMER_4 },
{ "Timer 5"             , SPELLCAT_TIMER_5 },
{ "Timer 6"             , SPELLCAT_TIMER_6 },
{ "Transport"           , SPELLCAT_TRANSPORT },
{ "Undead"              , SPELLCAT_UNDEAD },
{ "Utility Beneficial"  , SPELLCAT_UTILITY_BENEFICIAL },
{ "Utility Detrimental" , SPELLCAT_UTILITY_DETRIMENTAL },
{ "Velious"             , SPELLCAT_VELIOUS },
{ "Visages"             , SPELLCAT_VISAGES },
{ "Vision"              , SPELLCAT_VISION },
{ "Wisdom/Intelligence" , SPELLCAT_WISDOM_INTELLIGENCE },
{ "Traps"               , SPELLCAT_TRAPS },
{ "Auras"               , SPELLCAT_AURAS },
{ "Endurance"           , SPELLCAT_ENDURANCE },
{ "Serpent's Spine"     , SPELLCAT_SERPENTS_SPINE },
{ "Corruption"          , SPELLCAT_CORRUPTION },
{ "Learning"            , SPELLCAT_LEARNING },
{ "Chromatic"           , SPELLCAT_CHROMATIC },
{ "Prismatic"           , SPELLCAT_PRISMATIC },
{ "Sum: Swarm"          , SPELLCAT_SUM_SWARM },
{ "Delayed"             , SPELLCAT_DELAYED },
{ "Temporary"           , SPELLCAT_TEMPORARY },
{ "Twincast"            , SPELLCAT_TWINCAST },
{ "Sum: Bodyguard"      , SPELLCAT_SUM_BODYGUARD },
{ "Humanoid"            , SPELLCAT_HUMANOID },
{ "Haste/Spell Focus"   , SPELLCAT_HASTE_SPELL_FOCUS },
{ "Timer 7"             , SPELLCAT_TIMER_7 },
{ "Timer 8"             , SPELLCAT_TIMER_8 },
{ "Timer 9"             , SPELLCAT_TIMER_9 },
{ "Timer 10"            , SPELLCAT_TIMER_10 },
{ "Timer 11"            , SPELLCAT_TIMER_11 },
{ "Timer 12"            , SPELLCAT_TIMER_12 },
{ "Hatred"              , SPELLCAT_HATRED },
{ "Fast"                , SPELLCAT_FAST },
{ "Illusion: Special"   , SPELLCAT_ILLUSION_SPECIAL },
{ "Timer 13"            , SPELLCAT_TIMER_13 },
{ "Timer 14"            , SPELLCAT_TIMER_14 },
{ "Timer 15"            , SPELLCAT_TIMER_15 },
{ "Timer 16"            , SPELLCAT_TIMER_16 },
{ "Timer 17"            , SPELLCAT_TIMER_17 },
{ "Timer 18"            , SPELLCAT_TIMER_18 },
{ "Timer 19"            , SPELLCAT_TIMER_19 },
{ "Timer 20"            , SPELLCAT_TIMER_20 },
{ "Alaris"              , SPELLCAT_ALARIS },
{ "Combination"         , SPELLCAT_COMBINATION },
{ "Independent"         , SPELLCAT_INDEPENDENT },
{ "Skill Attacks"       , SPELLCAT_SKILL_ATTACKS },
{ "Incoming"            , SPELLCAT_INCOMING },
{ "Curse"               , SPELLCAT_CURSE },
{ "Timer 21"            , SPELLCAT_TIMER_21 },
{ "Timer 22"            , SPELLCAT_TIMER_22 },
{ "Timer 23"            , SPELLCAT_TIMER_23 },
{ "Timer 24"            , SPELLCAT_TIMER_24 },
{ "Timer 25"            , SPELLCAT_TIMER_25 },
{ "Drunkenness"         , SPELLCAT_DRUNKENNESS },
{ "Throwing"            , SPELLCAT_THROWING },
{ "Melee Damage"        , SPELLCAT_MELEE_DAMAGE },
}
*/

/* SPA

From eqlib/Spells.h

// EQ Spell "Affect"
// http://everquest.fanra.info/wiki/SPA_list
enum eEQSPA
{
	SPA_HP                                  = 0,
	SPA_AC                                  = 1,
	SPA_ATTACK_POWER                        = 2,
	SPA_MOVEMENT_RATE                       = 3,
	SPA_STR                                 = 4,
	SPA_DEX                                 = 5,
	SPA_AGI                                 = 6,
	SPA_STA                                 = 7,
	SPA_INT                                 = 8,
	SPA_WIS                                 = 9,
	SPA_CHA                                 = 10,
	SPA_HASTE                               = 11, // "Melee Speed"
	SPA_INVISIBILITY                        = 12,
	SPA_SEE_INVIS                           = 13,
	SPA_ENDURING_BREATH                     = 14,
	SPA_MANA                                = 15,
	SPA_NPC_FRENZY                          = 16,
	SPA_NPC_AWARENESS                       = 17,
	SPA_NPC_AGGRO                           = 18,
	SPA_NPC_FACTION                         = 19,
	SPA_BLINDNESS                           = 20,
	SPA_STUN                                = 21,
	SPA_CHARM                               = 22,
	SPA_FEAR                                = 23,
	SPA_FATIGUE                             = 24,
	SPA_BIND_AFFINITY                       = 25,
	SPA_GATE                                = 26,
	SPA_DISPEL_MAGIC                        = 27,
	SPA_INVIS_VS_UNDEAD                     = 28,
	SPA_INVIS_VS_ANIMALS                    = 29,
	SPA_NPC_AGGRO_RADIUS                    = 30,
	SPA_ENTHRALL                            = 31,
	SPA_CREATE_ITEM                         = 32,
	SPA_SUMMON_PET                          = 33,
	SPA_CONFUSE                             = 34,
	SPA_DISEASE                             = 35,
	SPA_POISON                              = 36,
	SPA_DETECT_HOSTILE                      = 37,
	SPA_DETECT_MAGIC                        = 38,
	SPA_NO_TWINCAST                         = 39,
	SPA_INVULNERABILITY                     = 40,
	SPA_BANISH                              = 41,
	SPA_SHADOW_STEP                         = 42,
	SPA_BERSERK                             = 43,
	SPA_LYCANTHROPY                         = 44,
	SPA_VAMPIRISM                           = 45,
	SPA_RESIST_FIRE                         = 46,
	SPA_RESIST_COLD                         = 47,
	SPA_RESIST_POISON                       = 48,
	SPA_RESIST_DISEASE                      = 49,
	SPA_RESIST_MAGIC                        = 50,
	SPA_DETECT_TRAPS                        = 51,
	SPA_DETECT_UNDEAD                       = 52,
	SPA_DETECT_SUMMONED                     = 53,
	SPA_DETECT_ANIMALS                      = 54,
	SPA_STONESKIN                           = 55,
	SPA_TRUE_NORTH                          = 56,
	SPA_LEVITATION                          = 57,
	SPA_CHANGE_FORM                         = 58,
	SPA_DAMAGE_SHIELD                       = 59,
	SPA_TRANSFER_ITEM                       = 60,
	SPA_ITEM_LORE                           = 61,
	SPA_ITEM_IDENTIFY                       = 62,
	SPA_NPC_WIPE_HATE_LIST                  = 63,
	SPA_SPIN_STUN                           = 64,
	SPA_INFRAVISION                         = 65,
	SPA_ULTRAVISION                         = 66,
	SPA_EYE_OF_ZOMM                         = 67,
	SPA_RECLAIM_ENERGY                      = 68,
	SPA_MAX_HP                              = 69,
	SPA_CORPSE_BOMB                         = 70,
	SPA_CREATE_UNDEAD                       = 71,
	SPA_PRESERVE_CORPSE                     = 72,
	SPA_BIND_SIGHT                          = 73,
	SPA_FEIGN_DEATH                         = 74,
	SPA_VENTRILOQUISM                       = 75,
	SPA_SENTINEL                            = 76,
	SPA_LOCATE_CORPSE                       = 77,
	SPA_SPELL_SHIELD                        = 78,
	SPA_INSTANT_HP                          = 79,
	SPA_ENCHANT_LIGHT                       = 80,
	SPA_RESURRECT                           = 81,
	SPA_SUMMON_TARGET                       = 82,
	SPA_PORTAL                              = 83,
	SPA_HP_NPC_ONLY                         = 84,
	SPA_MELEE_PROC                          = 85,
	SPA_NPC_HELP_RADIUS                     = 86,
	SPA_MAGNIFICATION                       = 87,
	SPA_EVACUATE                            = 88,
	SPA_HEIGHT                              = 89,
	SPA_IGNORE_PET                          = 90,
	SPA_SUMMON_CORPSE                       = 91,
	SPA_HATE                                = 92,
	SPA_WEATHER_CONTROL                     = 93,
	SPA_FRAGILE                             = 94,
	SPA_SACRIFICE                           = 95,
	SPA_SILENCE                             = 96,
	SPA_MAX_MANA                            = 97,
	SPA_BARD_HASTE                          = 98,
	SPA_ROOT                                = 99,
	SPA_HEALDOT                             = 100,
	SPA_COMPLETEHEAL                        = 101,
	SPA_PET_FEARLESS                        = 102,
	SPA_CALL_PET                            = 103,
	SPA_TRANSLOCATE                         = 104,
	SPA_NPC_ANTI_GATE                       = 105,
	SPA_BEASTLORD_PET                       = 106,
	SPA_ALTER_PET_LEVEL                     = 107,
	SPA_FAMILIAR                            = 108,
	SPA_CREATE_ITEM_IN_BAG                  = 109,
	SPA_ARCHERY                             = 110,
	SPA_RESIST_ALL                          = 111,
	SPA_FIZZLE_SKILL                        = 112,
	SPA_SUMMON_MOUNT                        = 113,
	SPA_MODIFY_HATE                         = 114,
	SPA_CORNUCOPIA                          = 115,
	SPA_CURSE                               = 116,
	SPA_HIT_MAGIC                           = 117,
	SPA_AMPLIFICATION                       = 118,
	SPA_ATTACK_SPEED_MAX                    = 119,
	SPA_HEALMOD                             = 120,
	SPA_IRONMAIDEN                          = 121,
	SPA_REDUCESKILL                         = 122,
	SPA_IMMUNITY                            = 123,
	SPA_FOCUS_DAMAGE_MOD                    = 124,
	SPA_FOCUS_HEAL_MOD                      = 125,
	SPA_FOCUS_RESIST_MOD                    = 126,
	SPA_FOCUS_CAST_TIME_MOD                 = 127,
	SPA_FOCUS_DURATION_MOD                  = 128,
	SPA_FOCUS_RANGE_MOD                     = 129,
	SPA_FOCUS_HATE_MOD                      = 130,
	SPA_FOCUS_REAGENT_MOD                   = 131,
	SPA_FOCUS_MANACOST_MOD                  = 132,
	SPA_FOCUS_STUNTIME_MOD                  = 133,
	SPA_FOCUS_LEVEL_MAX                     = 134,
	SPA_FOCUS_RESIST_TYPE                   = 135,
	SPA_FOCUS_TARGET_TYPE                   = 136,
	SPA_FOCUS_WHICH_SPA                     = 137,
	SPA_FOCUS_BENEFICIAL                    = 138,
	SPA_FOCUS_WHICH_SPELL                   = 139,
	SPA_FOCUS_DURATION_MIN                  = 140,
	SPA_FOCUS_INSTANT_ONLY                  = 141,
	SPA_FOCUS_LEVEL_MIN                     = 142,
	SPA_FOCUS_CASTTIME_MIN                  = 143,
	SPA_FOCUS_CASTTIME_MAX                  = 144,
	SPA_NPC_PORTAL_WARDER_BANISH            = 145,
	SPA_PORTAL_LOCATIONS                    = 146,
	SPA_PERCENT_HEAL                        = 147,
	SPA_STACKING_BLOCK                      = 148,
	SPA_STRIP_VIRTUAL_SLOT                  = 149,
	SPA_DIVINE_INTERVENTION                 = 150,
	SPA_POCKET_PET                          = 151,
	SPA_PET_SWARM                           = 152,
	SPA_HEALTH_BALANCE                      = 153,
	SPA_CANCEL_NEGATIVE_MAGIC               = 154,
	SPA_POP_RESURRECT                       = 155,
	SPA_MIRROR                              = 156,
	SPA_FEEDBACK                            = 157,
	SPA_REFLECT                             = 158,
	SPA_MODIFY_ALL_STATS                    = 159,
	SPA_CHANGE_SOBRIETY                     = 160,
	SPA_SPELL_GUARD                         = 161,
	SPA_MELEE_GUARD                         = 162,
	SPA_ABSORB_HIT                          = 163,
	SPA_OBJECT_SENSE_TRAP                   = 164,
	SPA_OBJECT_DISARM_TRAP                  = 165,
	SPA_OBJECT_PICKLOCK                     = 166,
	SPA_FOCUS_PET                           = 167,
	SPA_DEFENSIVE                           = 168,
	SPA_CRITICAL_MELEE                      = 169,
	SPA_CRITICAL_SPELL                      = 170,
	SPA_CRIPPLING_BLOW                      = 171,
	SPA_EVASION                             = 172,
	SPA_RIPOSTE                             = 173,
	SPA_DODGE                               = 174,
	SPA_PARRY                               = 175,
	SPA_DUAL_WIELD                          = 176,
	SPA_DOUBLE_ATTACK                       = 177,
	SPA_MELEE_LIFETAP                       = 178,
	SPA_PURETONE                            = 179,
	SPA_SANCTIFICATION                      = 180,
	SPA_FEARLESS                            = 181,
	SPA_HUNDRED_HANDS                       = 182,
	SPA_SKILL_INCREASE_CHANCE               = 183, // Unused
	SPA_ACCURACY                            = 184,
	SPA_SKILL_DAMAGE_MOD                    = 185,
	SPA_MIN_DAMAGE_DONE_MOD                 = 186,
	SPA_MANA_BALANCE                        = 187,
	SPA_BLOCK                               = 188,
	SPA_ENDURANCE                           = 189,
	SPA_INCREASE_MAX_ENDURANCE              = 190,
	SPA_AMNESIA                             = 191,
	SPA_HATE_OVER_TIME                      = 192,
	SPA_SKILL_ATTACK                        = 193,
	SPA_FADE                                = 194,
	SPA_STUN_RESIST                         = 195,
	SPA_STRIKETHROUGH1                      = 196, // Deprecated
	SPA_SKILL_DAMAGE_TAKEN                  = 197,
	SPA_INSTANT_ENDURANCE                   = 198,
	SPA_TAUNT                               = 199,
	SPA_PROC_CHANCE                         = 200,
	SPA_RANGE_ABILITY                       = 201,
	SPA_ILLUSION_OTHERS                     = 202,
	SPA_MASS_GROUP_BUFF                     = 203,
	SPA_GROUP_FEAR_IMMUNITY                 = 204,
	SPA_RAMPAGE                             = 205,
	SPA_AE_TAUNT                            = 206,
	SPA_FLESH_TO_BONE                       = 207,
	SPA_PURGE_POISON                        = 208,
	SPA_CANCEL_BENEFICIAL                   = 209,
	SPA_SHIELD_CASTER                       = 210,
	SPA_DESTRUCTIVE_FORCE                   = 211,
	SPA_FOCUS_FRENZIED_DEVASTATION          = 212,
	SPA_PET_PCT_MAX_HP                      = 213,
	SPA_HP_MAX_HP                           = 214,
	SPA_PET_PCT_AVOIDANCE                   = 215,
	SPA_MELEE_ACCURACY                      = 216,
	SPA_HEADSHOT                            = 217,
	SPA_PET_CRIT_MELEE                      = 218,
	SPA_SLAY_UNDEAD                         = 219,
	SPA_INCREASE_SKILL_DAMAGE               = 220,
	SPA_REDUCE_WEIGHT                       = 221,
	SPA_BLOCK_BEHIND                        = 222,
	SPA_DOUBLE_RIPOSTE                      = 223,
	SPA_ADD_RIPOSTE                         = 224,
	SPA_GIVE_DOUBLE_ATTACK                  = 225,
	SPA_2H_BASH                             = 226,
	SPA_REDUCE_SKILL_TIMER                  = 227,
	SPA_ACROBATICS                          = 228,
	SPA_CAST_THROUGH_STUN                   = 229,
	SPA_EXTENDED_SHIELDING                  = 230,
	SPA_BASH_CHANCE                         = 231,
	SPA_DIVINE_SAVE                         = 232,
	SPA_METABOLISM                          = 233,
	SPA_POISON_MASTERY                      = 234,
	SPA_FOCUS_CHANNELING                    = 235,
	SPA_FREE_PET                            = 236,
	SPA_PET_AFFINITY                        = 237,
	SPA_PERM_ILLUSION                       = 238,
	SPA_STONEWALL                           = 239,
	SPA_STRING_UNBREAKABLE                  = 240,
	SPA_IMPROVE_RECLAIM_ENERGY              = 241,
	SPA_INCREASE_CHANGE_MEMWIPE             = 242,
	SPA_ENHANCED_CHARM                      = 243,
	SPA_ENHANCED_ROOT                       = 244,
	SPA_TRAP_CIRCUMVENTION                  = 245,
	SPA_INCREASE_AIR_SUPPLY                 = 246,
	SPA_INCREASE_MAX_SKILL                  = 247,
	SPA_EXTRA_SPECIALIZATION                = 248,
	SPA_OFFHAND_MIN_WEAPON_DAMAGE           = 249,
	SPA_INCREASE_PROC_CHANCE                = 250,
	SPA_ENDLESS_QUIVER                      = 251,
	SPA_BACKSTAB_FRONT                      = 252,
	SPA_CHAOTIC_STAB                        = 253,
	SPA_NOSPELL                             = 254,
	SPA_SHIELDING_DURATION_MOD              = 255,
	SPA_SHROUD_OF_STEALTH                   = 256,
	SPA_GIVE_PET_HOLD                       = 257, // Deprecated
	SPA_TRIPLE_BACKSTAB                     = 258,
	SPA_AC_LIMIT_MOD                        = 259,
	SPA_ADD_INSTRUMENT_MOD                  = 260,
	SPA_SONG_MOD_CAP                        = 261,
	SPA_INCREASE_STAT_CAP                   = 262,
	SPA_TRADESKILL_MASTERY                  = 263,
	SPA_REDUCE_AA_TIMER                     = 264,
	SPA_NO_FIZZLE                           = 265,
	SPA_ADD_2H_ATTACK_CHANCE                = 266,
	SPA_ADD_PET_COMMANDS                    = 267,
	SPA_ALCHEMY_FAIL_RATE                   = 268,
	SPA_FIRST_AID                           = 269,
	SPA_EXTEND_SONG_RANGE                   = 270,
	SPA_BASE_RUN_MOD                        = 271,
	SPA_INCREASE_CASTING_LEVEL              = 272,
	SPA_DOTCRIT                             = 273,
	SPA_HEALCRIT                            = 274,
	SPA_MENDCRIT                            = 275,
	SPA_DUAL_WIELD_AMT                      = 276,
	SPA_EXTRA_DI_CHANCE                     = 277,
	SPA_FINISHING_BLOW                      = 278,
	SPA_FLURRY                              = 279,
	SPA_PET_FLURRY                          = 280,
	SPA_PET_FEIGN                           = 281,
	SPA_INCREASE_BANDAGE_AMT                = 282,
	SPA_WU_ATTACK                           = 283,
	SPA_IMPROVE_LOH                         = 284,
	SPA_NIMBLE_EVASION                      = 285,
	SPA_FOCUS_DAMAGE_AMT                    = 286,
	SPA_FOCUS_DURATION_AMT                  = 287,
	SPA_ADD_PROC_HIT                        = 288,
	SPA_DOOM_EFFECT                         = 289,
	SPA_INCREASE_RUN_SPEED_CAP              = 290,
	SPA_PURIFY                              = 291,
	SPA_STRIKETHROUGH                       = 292,
	SPA_STUN_RESIST2                        = 293,
	SPA_SPELL_CRIT_CHANCE                   = 294,
	SPA_REDUCE_SPECIAL_TIMER                = 295,
	SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL        = 296,
	SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL        = 297,
	SPA_TINY_COMPANION                      = 298,
	SPA_WAKE_DEAD                           = 299,
	SPA_DOPPELGANGER                        = 300,
	SPA_INCREASE_RANGE_DMG                  = 301,
	SPA_FOCUS_DAMAGE_MOD_CRIT               = 302,
	SPA_FOCUS_DAMAGE_AMT_CRIT               = 303,
	SPA_SECONDARY_RIPOSTE_MOD               = 304,
	SPA_DAMAGE_SHIELD_MOD                   = 305,
	SPA_WEAK_DEAD_2                         = 306,
	SPA_APPRAISAL                           = 307,
	SPA_ZONE_SUSPEND_MINION                 = 308,
	SPA_TELEPORT_CASTERS_BINDPOINT          = 309,
	SPA_FOCUS_REUSE_TIMER                   = 310,
	SPA_FOCUS_COMBAT_SKILL                  = 311,
	SPA_OBSERVER                            = 312,
	SPA_FORAGE_MASTER                       = 313,
	SPA_IMPROVED_INVIS                      = 314,
	SPA_IMPROVED_INVIS_UNDEAD               = 315,
	SPA_IMPROVED_INVIS_ANIMALS              = 316,
	SPA_INCREASE_WORN_HP_REGEN_CAP          = 317,
	SPA_INCREASE_WORN_MANA_REGEN_CAP        = 318,
	SPA_CRITICAL_HP_REGEN                   = 319,
	SPA_SHIELD_BLOCK_CHANCE                 = 320,
	SPA_REDUCE_TARGET_HATE                  = 321,
	SPA_GATE_STARTING_CITY                  = 322,
	SPA_DEFENSIVE_PROC                      = 323,
	SPA_HP_FOR_MANA                         = 324,
	SPA_NO_BREAK_AE_SNEAK                   = 325,
	SPA_ADD_SPELL_SLOTS                     = 326,
	SPA_ADD_BUFF_SLOTS                      = 327,
	SPA_INCREASE_NEGATIVE_HP_LIMIT          = 328,
	SPA_MANA_ABSORB_PCT_DMG                 = 329,
	SPA_CRIT_ATTACK_MODIFIER                = 330,
	SPA_FAIL_ALCHEMY_ITEM_RECOVERY          = 331,
	SPA_SUMMON_TO_CORPSE                    = 332,
	SPA_DOOM_RUNE_EFFECT                    = 333,
	SPA_NO_MOVE_HP                          = 334,
	SPA_FOCUSED_IMMUNITY                    = 335,
	SPA_ILLUSIONARY_TARGET                  = 336,
	SPA_INCREASE_EXP_MOD                    = 337,
	SPA_EXPEDIENT_RECOVERY                  = 338,
	SPA_FOCUS_CASTING_PROC                  = 339,
	SPA_CHANCE_SPELL                        = 340,
	SPA_WORN_ATTACK_CAP                     = 341,
	SPA_NO_PANIC                            = 342,
	SPA_SPELL_INTERRUPT                     = 343,
	SPA_ITEM_CHANNELING                     = 344,
	SPA_ASSASSINATE_MAX_LEVEL               = 345,
	SPA_HEADSHOT_MAX_LEVEL                  = 346,
	SPA_DOUBLE_RANGED_ATTACK                = 347,
	SPA_FOCUS_MANA_MIN                      = 348,
	SPA_INCREASE_SHIELD_DMG                 = 349,
	SPA_MANABURN                            = 350,
	SPA_SPAWN_INTERACTIVE_OBJECT            = 351,
	SPA_INCREASE_TRAP_COUNT                 = 352,
	SPA_INCREASE_SOI_COUNT                  = 353,
	SPA_DEACTIVATE_ALL_TRAPS                = 354,
	SPA_LEARN_TRAP                          = 355,
	SPA_CHANGE_TRIGGER_TYPE                 = 356,
	SPA_FOCUS_MUTE                          = 357,
	SPA_INSTANT_MANA                        = 358,
	SPA_PASSIVE_SENSE_TRAP                  = 359,
	SPA_PROC_ON_KILL_SHOT                   = 360,
	SPA_PROC_ON_DEATH                       = 361,
	SPA_POTION_BELT                         = 362,
	SPA_BANDOLIER                           = 363,
	SPA_ADD_TRIPLE_ATTACK_CHANCE            = 364,
	SPA_PROC_ON_SPELL_KILL_SHOT             = 365,
	SPA_GROUP_SHIELDING                     = 366,
	SPA_MODIFY_BODY_TYPE                    = 367,
	SPA_MODIFY_FACTION                      = 368,
	SPA_CORRUPTION                          = 369,
	SPA_RESIST_CORRUPTION                   = 370,
	SPA_SLOW                                = 371,
	SPA_GRANT_FORAGING                      = 372,
	SPA_DOOM_ALWAYS                         = 373,
	SPA_TRIGGER_SPELL                       = 374,
	SPA_CRIT_DOT_DMG_MOD                    = 375,
	SPA_FLING                               = 376,
	SPA_DOOM_ENTITY                         = 377,
	SPA_RESIST_OTHER_SPA                    = 378,
	SPA_DIRECTIONAL_TELEPORT                = 379,
	SPA_EXPLOSIVE_KNOCKBACK                 = 380,
	SPA_FLING_TOWARD                        = 381,
	SPA_SUPPRESSION                         = 382,
	SPA_FOCUS_CASTING_PROC_NORMALIZED       = 383,
	SPA_FLING_AT                            = 384,
	SPA_FOCUS_WHICH_GROUP                   = 385,
	SPA_DOOM_DISPELLER                      = 386,
	SPA_DOOM_DISPELLEE                      = 387,
	SPA_SUMMON_ALL_CORPSES                  = 388,
	SPA_REFRESH_SPELL_TIMER                 = 389,
	SPA_LOCKOUT_SPELL_TIMER                 = 390,
	SPA_FOCUS_MANA_MAX                      = 391,
	SPA_FOCUS_HEAL_AMT                      = 392,
	SPA_FOCUS_HEAL_MOD_BENEFICIAL           = 393,
	SPA_FOCUS_HEAL_AMT_BENEFICIAL           = 394,
	SPA_FOCUS_HEAL_MOD_CRIT                 = 395,
	SPA_FOCUS_HEAL_AMT_CRIT                 = 396,
	SPA_ADD_PET_AC                          = 397,
	SPA_FOCUS_SWARM_PET_DURATION            = 398,
	SPA_FOCUS_TWINCAST_CHANCE               = 399,
	SPA_HEALBURN                            = 400,
	SPA_MANA_IGNITE                         = 401,
	SPA_ENDURANCE_IGNITE                    = 402,
	SPA_FOCUS_SPELL_CLASS                   = 403,
	SPA_FOCUS_SPELL_SUBCLASS                = 404,
	SPA_STAFF_BLOCK_CHANCE                  = 405,
	SPA_DOOM_LIMIT_USE                      = 406,
	SPA_DOOM_FOCUS_USED                     = 407,
	SPA_LIMIT_HP                            = 408,
	SPA_LIMIT_MANA                          = 409,
	SPA_LIMIT_ENDURANCE                     = 410,
	SPA_FOCUS_LIMIT_CLASS                   = 411,
	SPA_FOCUS_LIMIT_RACE                    = 412,
	SPA_FOCUS_BASE_EFFECTS                  = 413,
	SPA_FOCUS_LIMIT_SKILL                   = 414,
	SPA_FOCUS_LIMIT_ITEM_CLASS              = 415,
	SPA_AC2                                 = 416,
	SPA_MANA2                               = 417,
	SPA_FOCUS_INCREASE_SKILL_DMG_2          = 418,
	SPA_PROC_EFFECT_2                       = 419,
	SPA_FOCUS_LIMIT_USE                     = 420,
	SPA_FOCUS_LIMIT_USE_AMT                 = 421,
	SPA_FOCUS_LIMIT_USE_MIN                 = 422,
	SPA_FOCUS_LIMIT_USE_TYPE                = 423,
	SPA_GRAVITATE                           = 424,
	SPA_FLY                                 = 425,
	SPA_ADD_EXTENDED_TARGET_SLOTS           = 426,
	SPA_SKILL_PROC                          = 427,
	SPA_PROC_SKILL_MODIFIER                 = 428,
	SPA_SKILL_PROC_SUCCESS                  = 429,
	SPA_POST_EFFECT                         = 430,
	SPA_POST_EFFECT_DATA                    = 431,
	SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS   = 432,
	SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT    = 433,
	SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2  = 434,
	SPA_FRAGILE_DEFENSE                     = 435,
	SPA_FREEZE_BUFF_TIMER                   = 436,
	SPA_TELEPORT_TO_ANCHOR                  = 437,
	SPA_TRANSLOCATE_TO_ANCHOR               = 438,
	SPA_ASSASSINATE                         = 439,
	SPA_FINISHING_BLOW_MAX                  = 440,
	SPA_DISTANCE_REMOVAL                    = 441,
	SPA_REQUIRE_TARGET_DOOM                 = 442,
	SPA_REQUIRE_CASTER_DOOM                 = 443,
	SPA_IMPROVED_TAUNT                      = 444,
	SPA_ADD_MERC_SLOT                       = 445,
	SPA_STACKER_A                           = 446,
	SPA_STACKER_B                           = 447,
	SPA_STACKER_C                           = 448,
	SPA_STACKER_D                           = 449,
	SPA_DOT_GUARD                           = 450,
	SPA_MELEE_THRESHOLD_GUARD               = 451,
	SPA_SPELL_THRESHOLD_GUARD               = 452,
	SPA_MELEE_THRESHOLD_DOOM                = 453,
	SPA_SPELL_THRESHOLD_DOOM                = 454,
	SPA_ADD_HATE_PCT                        = 455,
	SPA_ADD_HATE_OVER_TIME_PCT              = 456,
	SPA_RESOURCE_TAP                        = 457,
	SPA_FACTION_MOD                         = 458,
	SPA_SKILL_DAMAGE_MOD_2                  = 459,
	SPA_OVERRIDE_NOT_FOCUSABLE              = 460,
	SPA_FOCUS_DAMAGE_MOD_2                  = 461,
	SPA_FOCUS_DAMAGE_AMT_2                  = 462,
	SPA_SHIELD                              = 463,
	SPA_PC_PET_RAMPAGE                      = 464,
	SPA_PC_PET_AE_RAMPAGE                   = 465,
	SPA_PC_PET_FLURRY                       = 466,
	SPA_DAMAGE_SHIELD_MITIGATION_AMT        = 467,
	SPA_DAMAGE_SHIELD_MITIGATION_PCT        = 468,
	SPA_CHANCE_BEST_IN_SPELL_GROUP          = 469,
	SPA_TRIGGER_BEST_IN_SPELL_GROUP         = 470,
	SPA_DOUBLE_MELEE_ATTACKS                = 471,
	SPA_AA_BUY_NEXT_RANK                    = 472,
	SPA_DOUBLE_BACKSTAB_FRONT               = 473,
	SPA_PET_MELEE_CRIT_DMG_MOD              = 474,
	SPA_TRIGGER_SPELL_NON_ITEM              = 475,
	SPA_WEAPON_STANCE                       = 476,
	SPA_HATELIST_TO_TOP                     = 477,
	SPA_HATELIST_TO_TAIL                    = 478,
	SPA_FOCUS_LIMIT_MIN_VALUE               = 479,
	SPA_FOCUS_LIMIT_MAX_VALUE               = 480,
	SPA_FOCUS_CAST_SPELL_ON_LAND            = 481,
	SPA_SKILL_BASE_DAMAGE_MOD               = 482,
	SPA_FOCUS_INCOMING_DMG_MOD              = 483,
	SPA_FOCUS_INCOMING_DMG_AMT              = 484,
	SPA_FOCUS_LIMIT_CASTER_CLASS            = 485,
	SPA_FOCUS_LIMIT_SAME_CASTER             = 486,
	SPA_EXTEND_TRADESKILL_CAP               = 487,
	SPA_DEFENDER_MELEE_FORCE_PCT            = 488,
	SPA_WORN_ENDURANCE_REGEN_CAP            = 489,
	SPA_FOCUS_MIN_REUSE_TIME                = 490,
	SPA_FOCUS_MAX_REUSE_TIME                = 491,
	SPA_FOCUS_ENDURANCE_MIN                 = 492,
	SPA_FOCUS_ENDURANCE_MAX                 = 493,
	SPA_PET_ADD_ATK                         = 494,
	SPA_FOCUS_DURATION_MAX                  = 495,
	SPA_CRIT_MELEE_DMG_MOD_MAX              = 496,
	SPA_FOCUS_CAST_PROC_NO_BYPASS           = 497,
	SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT        = 498,
	SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT      = 499,
	SPA_FOCUS_CAST_TIME_MOD2                = 500,
	SPA_FOCUS_CAST_TIME_AMT                 = 501,
	SPA_FEARSTUN                            = 502,
	SPA_MELEE_DMG_POSITION_MOD              = 503,
	SPA_MELEE_DMG_POSITION_AMT              = 504,
	SPA_DMG_TAKEN_POSITION_MOD              = 505,
	SPA_DMG_TAKEN_POSITION_AMT              = 506,
	SPA_AMPLIFY_MOD                         = 507,
	SPA_AMPLIFY_AMT                         = 508,
	SPA_HEALTH_TRANSFER                     = 509,
	SPA_FOCUS_RESIST_INCOMING               = 510,
	SPA_FOCUS_TIMER_MIN                     = 511,
	SPA_PROC_TIMER_MOD                      = 512,
	SPA_MANA_MAX                            = 513,
	SPA_ENDURANCE_MAX                       = 514,
	SPA_AC_AVOIDANCE_MAX                    = 515,
	SPA_AC_MITIGATION_MAX                   = 516,
	SPA_ATTACK_OFFENSE_MAX                  = 517,
	SPA_ATTACK_ACCURACY_MAX                 = 518,
	SPA_LUCK_AMT                            = 519,
	SPA_LUCK_PCT                            = 520,
	SPA_ENDURANCE_ABSORB_PCT_DMG            = 521,
	SPA_INSTANT_MANA_PCT                    = 522,
	SPA_INSTANT_ENDURANCE_PCT               = 523,
	SPA_DURATION_HP_PCT                     = 524,
	SPA_DURATION_MANA_PCT                   = 525,
	SPA_DURATION_ENDURANCE_PCT              = 526,
}
*/

/* From main/MQ2Spells.cpp 12/28/2021

 e.g. eEQSPA::SPA_HP

static const ci_unordered::map<std::string_view, eEQSPA> s_spaLookup = {
{ "HP"                                , SPA_HP },
{ "AC"                                , SPA_AC },
{ "ATTACK_POWER"                      , SPA_ATTACK_POWER },
{ "MOVEMENT_RATE"                     , SPA_MOVEMENT_RATE },
{ "STR"                               , SPA_STR },
{ "DEX"                               , SPA_DEX },
{ "AGI"                               , SPA_AGI },
{ "STA"                               , SPA_STA },
{ "INT"                               , SPA_INT },
{ "WIS"                               , SPA_WIS },
{ "CHA"                               , SPA_CHA },
{ "HASTE"                             , SPA_HASTE },
{ "INVISIBILITY"                      , SPA_INVISIBILITY },
{ "SEE_INVIS"                         , SPA_SEE_INVIS },
{ "ENDURING_BREATH"                   , SPA_ENDURING_BREATH },
{ "MANA"                              , SPA_MANA },
{ "NPC_FRENZY"                        , SPA_NPC_FRENZY },
{ "NPC_AWARENESS"                     , SPA_NPC_AWARENESS },
{ "NPC_AGGRO"                         , SPA_NPC_AGGRO },
{ "NPC_FACTION"                       , SPA_NPC_FACTION },
{ "BLINDNESS"                         , SPA_BLINDNESS },
{ "STUN"                              , SPA_STUN },
{ "CHARM"                             , SPA_CHARM },
{ "FEAR"                              , SPA_FEAR },
{ "FATIGUE"                           , SPA_FATIGUE },
{ "BIND_AFFINITY"                     , SPA_BIND_AFFINITY },
{ "GATE"                              , SPA_GATE },
{ "DISPEL_MAGIC"                      , SPA_DISPEL_MAGIC },
{ "INVIS_VS_UNDEAD"                   , SPA_INVIS_VS_UNDEAD },
{ "INVIS_VS_ANIMALS"                  , SPA_INVIS_VS_ANIMALS },
{ "NPC_AGGRO_RADIUS"                  , SPA_NPC_AGGRO_RADIUS },
{ "ENTHRALL"                          , SPA_ENTHRALL },
{ "CREATE_ITEM"                       , SPA_CREATE_ITEM },
{ "SUMMON_PET"                        , SPA_SUMMON_PET },
{ "CONFUSE"                           , SPA_CONFUSE },
{ "DISEASE"                           , SPA_DISEASE },
{ "POISON"                            , SPA_POISON },
{ "DETECT_HOSTILE"                    , SPA_DETECT_HOSTILE },
{ "DETECT_MAGIC"                      , SPA_DETECT_MAGIC },
{ "NO_TWINCAST"                       , SPA_NO_TWINCAST },
{ "INVULNERABILITY"                   , SPA_INVULNERABILITY },
{ "BANISH"                            , SPA_BANISH },
{ "SHADOW_STEP"                       , SPA_SHADOW_STEP },
{ "BERSERK"                           , SPA_BERSERK },
{ "LYCANTHROPY"                       , SPA_LYCANTHROPY },
{ "VAMPIRISM"                         , SPA_VAMPIRISM },
{ "RESIST_FIRE"                       , SPA_RESIST_FIRE },
{ "RESIST_COLD"                       , SPA_RESIST_COLD },
{ "RESIST_POISON"                     , SPA_RESIST_POISON },
{ "RESIST_DISEASE"                    , SPA_RESIST_DISEASE },
{ "RESIST_MAGIC"                      , SPA_RESIST_MAGIC },
{ "DETECT_TRAPS"                      , SPA_DETECT_TRAPS },
{ "DETECT_UNDEAD"                     , SPA_DETECT_UNDEAD },
{ "DETECT_SUMMONED"                   , SPA_DETECT_SUMMONED },
{ "DETECT_ANIMALS"                    , SPA_DETECT_ANIMALS },
{ "STONESKIN"                         , SPA_STONESKIN },
{ "TRUE_NORTH"                        , SPA_TRUE_NORTH },
{ "LEVITATION"                        , SPA_LEVITATION },
{ "CHANGE_FORM"                       , SPA_CHANGE_FORM },
{ "DAMAGE_SHIELD"                     , SPA_DAMAGE_SHIELD },
{ "TRANSFER_ITEM"                     , SPA_TRANSFER_ITEM },
{ "ITEM_LORE"                         , SPA_ITEM_LORE },
{ "ITEM_IDENTIFY"                     , SPA_ITEM_IDENTIFY },
{ "NPC_WIPE_HATE_LIST"                , SPA_NPC_WIPE_HATE_LIST },
{ "SPIN_STUN"                         , SPA_SPIN_STUN },
{ "INFRAVISION"                       , SPA_INFRAVISION },
{ "ULTRAVISION"                       , SPA_ULTRAVISION },
{ "EYE_OF_ZOMM"                       , SPA_EYE_OF_ZOMM },
{ "RECLAIM_ENERGY"                    , SPA_RECLAIM_ENERGY },
{ "MAX_HP"                            , SPA_MAX_HP },
{ "CORPSE_BOMB"                       , SPA_CORPSE_BOMB },
{ "CREATE_UNDEAD"                     , SPA_CREATE_UNDEAD },
{ "PRESERVE_CORPSE"                   , SPA_PRESERVE_CORPSE },
{ "BIND_SIGHT"                        , SPA_BIND_SIGHT },
{ "FEIGN_DEATH"                       , SPA_FEIGN_DEATH },
{ "VENTRILOQUISM"                     , SPA_VENTRILOQUISM },
{ "SENTINEL"                          , SPA_SENTINEL },
{ "LOCATE_CORPSE"                     , SPA_LOCATE_CORPSE },
{ "SPELL_SHIELD"                      , SPA_SPELL_SHIELD },
{ "INSTANT_HP"                        , SPA_INSTANT_HP },
{ "ENCHANT_LIGHT"                     , SPA_ENCHANT_LIGHT },
{ "RESURRECT"                         , SPA_RESURRECT },
{ "SUMMON_TARGET"                     , SPA_SUMMON_TARGET },
{ "PORTAL"                            , SPA_PORTAL },
{ "HP_NPC_ONLY"                       , SPA_HP_NPC_ONLY },
{ "MELEE_PROC"                        , SPA_MELEE_PROC },
{ "NPC_HELP_RADIUS"                   , SPA_NPC_HELP_RADIUS },
{ "MAGNIFICATION"                     , SPA_MAGNIFICATION },
{ "EVACUATE"                          , SPA_EVACUATE },
{ "HEIGHT"                            , SPA_HEIGHT },
{ "IGNORE_PET"                        , SPA_IGNORE_PET },
{ "SUMMON_CORPSE"                     , SPA_SUMMON_CORPSE },
{ "HATE"                              , SPA_HATE },
{ "WEATHER_CONTROL"                   , SPA_WEATHER_CONTROL },
{ "FRAGILE"                           , SPA_FRAGILE },
{ "SACRIFICE"                         , SPA_SACRIFICE },
{ "SILENCE"                           , SPA_SILENCE },
{ "MAX_MANA"                          , SPA_MAX_MANA },
{ "BARD_HASTE"                        , SPA_BARD_HASTE },
{ "ROOT"                              , SPA_ROOT },
{ "HEALDOT"                           , SPA_HEALDOT },
{ "COMPLETEHEAL"                      , SPA_COMPLETEHEAL },
{ "PET_FEARLESS"                      , SPA_PET_FEARLESS },
{ "CALL_PET"                          , SPA_CALL_PET },
{ "TRANSLOCATE"                       , SPA_TRANSLOCATE },
{ "NPC_ANTI_GATE"                     , SPA_NPC_ANTI_GATE },
{ "BEASTLORD_PET"                     , SPA_BEASTLORD_PET },
{ "ALTER_PET_LEVEL"                   , SPA_ALTER_PET_LEVEL },
{ "FAMILIAR"                          , SPA_FAMILIAR },
{ "CREATE_ITEM_IN_BAG"                , SPA_CREATE_ITEM_IN_BAG },
{ "ARCHERY"                           , SPA_ARCHERY },
{ "RESIST_ALL"                        , SPA_RESIST_ALL },
{ "FIZZLE_SKILL"                      , SPA_FIZZLE_SKILL },
{ "SUMMON_MOUNT"                      , SPA_SUMMON_MOUNT },
{ "MODIFY_HATE"                       , SPA_MODIFY_HATE },
{ "CORNUCOPIA"                        , SPA_CORNUCOPIA },
{ "CURSE"                             , SPA_CURSE },
{ "HIT_MAGIC"                         , SPA_HIT_MAGIC },
{ "AMPLIFICATION"                     , SPA_AMPLIFICATION },
{ "ATTACK_SPEED_MAX"                  , SPA_ATTACK_SPEED_MAX },
{ "HEALMOD"                           , SPA_HEALMOD },
{ "IRONMAIDEN"                        , SPA_IRONMAIDEN },
{ "REDUCESKILL"                       , SPA_REDUCESKILL },
{ "IMMUNITY"                          , SPA_IMMUNITY },
{ "FOCUS_DAMAGE_MOD"                  , SPA_FOCUS_DAMAGE_MOD },
{ "FOCUS_HEAL_MOD"                    , SPA_FOCUS_HEAL_MOD },
{ "FOCUS_RESIST_MOD"                  , SPA_FOCUS_RESIST_MOD },
{ "FOCUS_CAST_TIME_MOD"               , SPA_FOCUS_CAST_TIME_MOD },
{ "FOCUS_DURATION_MOD"                , SPA_FOCUS_DURATION_MOD },
{ "FOCUS_RANGE_MOD"                   , SPA_FOCUS_RANGE_MOD },
{ "FOCUS_HATE_MOD"                    , SPA_FOCUS_HATE_MOD },
{ "FOCUS_REAGENT_MOD"                 , SPA_FOCUS_REAGENT_MOD },
{ "FOCUS_MANACOST_MOD"                , SPA_FOCUS_MANACOST_MOD },
{ "FOCUS_STUNTIME_MOD"                , SPA_FOCUS_STUNTIME_MOD },
{ "FOCUS_LEVEL_MAX"                   , SPA_FOCUS_LEVEL_MAX },
{ "FOCUS_RESIST_TYPE"                 , SPA_FOCUS_RESIST_TYPE },
{ "FOCUS_TARGET_TYPE"                 , SPA_FOCUS_TARGET_TYPE },
{ "FOCUS_WHICH_SPA"                   , SPA_FOCUS_WHICH_SPA },
{ "FOCUS_BENEFICIAL"                  , SPA_FOCUS_BENEFICIAL },
{ "FOCUS_WHICH_SPELL"                 , SPA_FOCUS_WHICH_SPELL },
{ "FOCUS_DURATION_MIN"                , SPA_FOCUS_DURATION_MIN },
{ "FOCUS_INSTANT_ONLY"                , SPA_FOCUS_INSTANT_ONLY },
{ "FOCUS_LEVEL_MIN"                   , SPA_FOCUS_LEVEL_MIN },
{ "FOCUS_CASTTIME_MIN"                , SPA_FOCUS_CASTTIME_MIN },
{ "FOCUS_CASTTIME_MAX"                , SPA_FOCUS_CASTTIME_MAX },
{ "NPC_PORTAL_WARDER_BANISH"          , SPA_NPC_PORTAL_WARDER_BANISH },
{ "PORTAL_LOCATIONS"                  , SPA_PORTAL_LOCATIONS },
{ "PERCENT_HEAL"                      , SPA_PERCENT_HEAL },
{ "STACKING_BLOCK"                    , SPA_STACKING_BLOCK },
{ "STRIP_VIRTUAL_SLOT"                , SPA_STRIP_VIRTUAL_SLOT },
{ "DIVINE_INTERVENTION"               , SPA_DIVINE_INTERVENTION },
{ "POCKET_PET"                        , SPA_POCKET_PET },
{ "PET_SWARM"                         , SPA_PET_SWARM },
{ "HEALTH_BALANCE"                    , SPA_HEALTH_BALANCE },
{ "CANCEL_NEGATIVE_MAGIC"             , SPA_CANCEL_NEGATIVE_MAGIC },
{ "POP_RESURRECT"                     , SPA_POP_RESURRECT },
{ "MIRROR"                            , SPA_MIRROR },
{ "FEEDBACK"                          , SPA_FEEDBACK },
{ "REFLECT"                           , SPA_REFLECT },
{ "MODIFY_ALL_STATS"                  , SPA_MODIFY_ALL_STATS },
{ "CHANGE_SOBRIETY"                   , SPA_CHANGE_SOBRIETY },
{ "SPELL_GUARD"                       , SPA_SPELL_GUARD },
{ "MELEE_GUARD"                       , SPA_MELEE_GUARD },
{ "ABSORB_HIT"                        , SPA_ABSORB_HIT },
{ "OBJECT_SENSE_TRAP"                 , SPA_OBJECT_SENSE_TRAP },
{ "OBJECT_DISARM_TRAP"                , SPA_OBJECT_DISARM_TRAP },
{ "OBJECT_PICKLOCK"                   , SPA_OBJECT_PICKLOCK },
{ "FOCUS_PET"                         , SPA_FOCUS_PET },
{ "DEFENSIVE"                         , SPA_DEFENSIVE },
{ "CRITICAL_MELEE"                    , SPA_CRITICAL_MELEE },
{ "CRITICAL_SPELL"                    , SPA_CRITICAL_SPELL },
{ "CRIPPLING_BLOW"                    , SPA_CRIPPLING_BLOW },
{ "EVASION"                           , SPA_EVASION },
{ "RIPOSTE"                           , SPA_RIPOSTE },
{ "DODGE"                             , SPA_DODGE },
{ "PARRY"                             , SPA_PARRY },
{ "DUAL_WIELD"                        , SPA_DUAL_WIELD },
{ "DOUBLE_ATTACK"                     , SPA_DOUBLE_ATTACK },
{ "MELEE_LIFETAP"                     , SPA_MELEE_LIFETAP },
{ "PURETONE"                          , SPA_PURETONE },
{ "SANCTIFICATION"                    , SPA_SANCTIFICATION },
{ "FEARLESS"                          , SPA_FEARLESS },
{ "HUNDRED_HANDS"                     , SPA_HUNDRED_HANDS },
{ "SKILL_INCREASE_CHANCE"             , SPA_SKILL_INCREASE_CHANCE },
{ "ACCURACY"                          , SPA_ACCURACY },
{ "SKILL_DAMAGE_MOD"                  , SPA_SKILL_DAMAGE_MOD },
{ "MIN_DAMAGE_DONE_MOD"               , SPA_MIN_DAMAGE_DONE_MOD },
{ "MANA_BALANCE"                      , SPA_MANA_BALANCE },
{ "BLOCK"                             , SPA_BLOCK },
{ "ENDURANCE"                         , SPA_ENDURANCE },
{ "INCREASE_MAX_ENDURANCE"            , SPA_INCREASE_MAX_ENDURANCE },
{ "AMNESIA"                           , SPA_AMNESIA },
{ "HATE_OVER_TIME"                    , SPA_HATE_OVER_TIME },
{ "SKILL_ATTACK"                      , SPA_SKILL_ATTACK },
{ "FADE"                              , SPA_FADE },
{ "STUN_RESIST"                       , SPA_STUN_RESIST },
{ "STRIKETHROUGH1"                    , SPA_STRIKETHROUGH1 },
{ "SKILL_DAMAGE_TAKEN"                , SPA_SKILL_DAMAGE_TAKEN },
{ "INSTANT_ENDURANCE"                 , SPA_INSTANT_ENDURANCE },
{ "TAUNT"                             , SPA_TAUNT },
{ "PROC_CHANCE"                       , SPA_PROC_CHANCE },
{ "RANGE_ABILITY"                     , SPA_RANGE_ABILITY },
{ "ILLUSION_OTHERS"                   , SPA_ILLUSION_OTHERS },
{ "MASS_GROUP_BUFF"                   , SPA_MASS_GROUP_BUFF },
{ "GROUP_FEAR_IMMUNITY"               , SPA_GROUP_FEAR_IMMUNITY },
{ "RAMPAGE"                           , SPA_RAMPAGE },
{ "AE_TAUNT"                          , SPA_AE_TAUNT },
{ "FLESH_TO_BONE"                     , SPA_FLESH_TO_BONE },
{ "PURGE_POISON"                      , SPA_PURGE_POISON },
{ "CANCEL_BENEFICIAL"                 , SPA_CANCEL_BENEFICIAL },
{ "SHIELD_CASTER"                     , SPA_SHIELD_CASTER },
{ "DESTRUCTIVE_FORCE"                 , SPA_DESTRUCTIVE_FORCE },
{ "FOCUS_FRENZIED_DEVASTATION"        , SPA_FOCUS_FRENZIED_DEVASTATION },
{ "PET_PCT_MAX_HP"                    , SPA_PET_PCT_MAX_HP },
{ "HP_MAX_HP"                         , SPA_HP_MAX_HP },
{ "PET_PCT_AVOIDANCE"                 , SPA_PET_PCT_AVOIDANCE },
{ "MELEE_ACCURACY"                    , SPA_MELEE_ACCURACY },
{ "HEADSHOT"                          , SPA_HEADSHOT },
{ "PET_CRIT_MELEE"                    , SPA_PET_CRIT_MELEE },
{ "SLAY_UNDEAD"                       , SPA_SLAY_UNDEAD },
{ "INCREASE_SKILL_DAMAGE"             , SPA_INCREASE_SKILL_DAMAGE },
{ "REDUCE_WEIGHT"                     , SPA_REDUCE_WEIGHT },
{ "BLOCK_BEHIND"                      , SPA_BLOCK_BEHIND },
{ "DOUBLE_RIPOSTE"                    , SPA_DOUBLE_RIPOSTE },
{ "ADD_RIPOSTE"                       , SPA_ADD_RIPOSTE },
{ "GIVE_DOUBLE_ATTACK"                , SPA_GIVE_DOUBLE_ATTACK },
{ "2H_BASH"                           , SPA_2H_BASH },
{ "REDUCE_SKILL_TIMER"                , SPA_REDUCE_SKILL_TIMER },
{ "ACROBATICS"                        , SPA_ACROBATICS },
{ "CAST_THROUGH_STUN"                 , SPA_CAST_THROUGH_STUN },
{ "EXTENDED_SHIELDING"                , SPA_EXTENDED_SHIELDING },
{ "BASH_CHANCE"                       , SPA_BASH_CHANCE },
{ "DIVINE_SAVE"                       , SPA_DIVINE_SAVE },
{ "METABOLISM"                        , SPA_METABOLISM },
{ "POISON_MASTERY"                    , SPA_POISON_MASTERY },
{ "FOCUS_CHANNELING"                  , SPA_FOCUS_CHANNELING },
{ "FREE_PET"                          , SPA_FREE_PET },
{ "PET_AFFINITY"                      , SPA_PET_AFFINITY },
{ "PERM_ILLUSION"                     , SPA_PERM_ILLUSION },
{ "STONEWALL"                         , SPA_STONEWALL },
{ "STRING_UNBREAKABLE"                , SPA_STRING_UNBREAKABLE },
{ "IMPROVE_RECLAIM_ENERGY"            , SPA_IMPROVE_RECLAIM_ENERGY },
{ "INCREASE_CHANGE_MEMWIPE"           , SPA_INCREASE_CHANGE_MEMWIPE },
{ "ENHANCED_CHARM"                    , SPA_ENHANCED_CHARM },
{ "ENHANCED_ROOT"                     , SPA_ENHANCED_ROOT },
{ "TRAP_CIRCUMVENTION"                , SPA_TRAP_CIRCUMVENTION },
{ "INCREASE_AIR_SUPPLY"               , SPA_INCREASE_AIR_SUPPLY },
{ "INCREASE_MAX_SKILL"                , SPA_INCREASE_MAX_SKILL },
{ "EXTRA_SPECIALIZATION"              , SPA_EXTRA_SPECIALIZATION },
{ "OFFHAND_MIN_WEAPON_DAMAGE"         , SPA_OFFHAND_MIN_WEAPON_DAMAGE },
{ "INCREASE_PROC_CHANCE"              , SPA_INCREASE_PROC_CHANCE },
{ "ENDLESS_QUIVER"                    , SPA_ENDLESS_QUIVER },
{ "BACKSTAB_FRONT"                    , SPA_BACKSTAB_FRONT },
{ "CHAOTIC_STAB"                      , SPA_CHAOTIC_STAB },
{ "NOSPELL"                           , SPA_NOSPELL },
{ "SHIELDING_DURATION_MOD"            , SPA_SHIELDING_DURATION_MOD },
{ "SHROUD_OF_STEALTH"                 , SPA_SHROUD_OF_STEALTH },
{ "GIVE_PET_HOLD"                     , SPA_GIVE_PET_HOLD },
{ "TRIPLE_BACKSTAB"                   , SPA_TRIPLE_BACKSTAB },
{ "AC_LIMIT_MOD"                      , SPA_AC_LIMIT_MOD },
{ "ADD_INSTRUMENT_MOD"                , SPA_ADD_INSTRUMENT_MOD },
{ "SONG_MOD_CAP"                      , SPA_SONG_MOD_CAP },
{ "INCREASE_STAT_CAP"                 , SPA_INCREASE_STAT_CAP },
{ "TRADESKILL_MASTERY"                , SPA_TRADESKILL_MASTERY },
{ "REDUCE_AA_TIMER"                   , SPA_REDUCE_AA_TIMER },
{ "NO_FIZZLE"                         , SPA_NO_FIZZLE },
{ "ADD_2H_ATTACK_CHANCE"              , SPA_ADD_2H_ATTACK_CHANCE },
{ "ADD_PET_COMMANDS"                  , SPA_ADD_PET_COMMANDS },
{ "ALCHEMY_FAIL_RATE"                 , SPA_ALCHEMY_FAIL_RATE },
{ "FIRST_AID"                         , SPA_FIRST_AID },
{ "EXTEND_SONG_RANGE"                 , SPA_EXTEND_SONG_RANGE },
{ "BASE_RUN_MOD"                      , SPA_BASE_RUN_MOD },
{ "INCREASE_CASTING_LEVEL"            , SPA_INCREASE_CASTING_LEVEL },
{ "DOTCRIT"                           , SPA_DOTCRIT },
{ "HEALCRIT"                          , SPA_HEALCRIT },
{ "MENDCRIT"                          , SPA_MENDCRIT },
{ "DUAL_WIELD_AMT"                    , SPA_DUAL_WIELD_AMT },
{ "EXTRA_DI_CHANCE"                   , SPA_EXTRA_DI_CHANCE },
{ "FINISHING_BLOW"                    , SPA_FINISHING_BLOW },
{ "FLURRY"                            , SPA_FLURRY },
{ "PET_FLURRY"                        , SPA_PET_FLURRY },
{ "PET_FEIGN"                         , SPA_PET_FEIGN },
{ "INCREASE_BANDAGE_AMT"              , SPA_INCREASE_BANDAGE_AMT },
{ "WU_ATTACK"                         , SPA_WU_ATTACK },
{ "IMPROVE_LOH"                       , SPA_IMPROVE_LOH },
{ "NIMBLE_EVASION"                    , SPA_NIMBLE_EVASION },
{ "FOCUS_DAMAGE_AMT"                  , SPA_FOCUS_DAMAGE_AMT },
{ "FOCUS_DURATION_AMT"                , SPA_FOCUS_DURATION_AMT },
{ "ADD_PROC_HIT"                      , SPA_ADD_PROC_HIT },
{ "DOOM_EFFECT"                       , SPA_DOOM_EFFECT },
{ "INCREASE_RUN_SPEED_CAP"            , SPA_INCREASE_RUN_SPEED_CAP },
{ "PURIFY"                            , SPA_PURIFY },
{ "STRIKETHROUGH"                     , SPA_STRIKETHROUGH },
{ "STUN_RESIST2"                      , SPA_STUN_RESIST2 },
{ "SPELL_CRIT_CHANCE"                 , SPA_SPELL_CRIT_CHANCE },
{ "REDUCE_SPECIAL_TIMER"              , SPA_REDUCE_SPECIAL_TIMER },
{ "FOCUS_DAMAGE_MOD_DETRIMENTAL"      , SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL },
{ "FOCUS_DAMAGE_AMT_DETRIMENTAL"      , SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL },
{ "TINY_COMPANION"                    , SPA_TINY_COMPANION },
{ "WAKE_DEAD"                         , SPA_WAKE_DEAD },
{ "DOPPELGANGER"                      , SPA_DOPPELGANGER },
{ "INCREASE_RANGE_DMG"                , SPA_INCREASE_RANGE_DMG },
{ "FOCUS_DAMAGE_MOD_CRIT"             , SPA_FOCUS_DAMAGE_MOD_CRIT },
{ "FOCUS_DAMAGE_AMT_CRIT"             , SPA_FOCUS_DAMAGE_AMT_CRIT },
{ "SECONDARY_RIPOSTE_MOD"             , SPA_SECONDARY_RIPOSTE_MOD },
{ "DAMAGE_SHIELD_MOD"                 , SPA_DAMAGE_SHIELD_MOD },
{ "WEAK_DEAD_2"                       , SPA_WEAK_DEAD_2 },
{ "APPRAISAL"                         , SPA_APPRAISAL },
{ "ZONE_SUSPEND_MINION"               , SPA_ZONE_SUSPEND_MINION },
{ "TELEPORT_CASTERS_BINDPOINT"        , SPA_TELEPORT_CASTERS_BINDPOINT },
{ "FOCUS_REUSE_TIMER"                 , SPA_FOCUS_REUSE_TIMER },
{ "FOCUS_COMBAT_SKILL"                , SPA_FOCUS_COMBAT_SKILL },
{ "OBSERVER"                          , SPA_OBSERVER },
{ "FORAGE_MASTER"                     , SPA_FORAGE_MASTER },
{ "IMPROVED_INVIS"                    , SPA_IMPROVED_INVIS },
{ "IMPROVED_INVIS_UNDEAD"             , SPA_IMPROVED_INVIS_UNDEAD },
{ "IMPROVED_INVIS_ANIMALS"            , SPA_IMPROVED_INVIS_ANIMALS },
{ "INCREASE_WORN_HP_REGEN_CAP"        , SPA_INCREASE_WORN_HP_REGEN_CAP },
{ "INCREASE_WORN_MANA_REGEN_CAP"      , SPA_INCREASE_WORN_MANA_REGEN_CAP },
{ "CRITICAL_HP_REGEN"                 , SPA_CRITICAL_HP_REGEN },
{ "SHIELD_BLOCK_CHANCE"               , SPA_SHIELD_BLOCK_CHANCE },
{ "REDUCE_TARGET_HATE"                , SPA_REDUCE_TARGET_HATE },
{ "GATE_STARTING_CITY"                , SPA_GATE_STARTING_CITY },
{ "DEFENSIVE_PROC"                    , SPA_DEFENSIVE_PROC },
{ "HP_FOR_MANA"                       , SPA_HP_FOR_MANA },
{ "NO_BREAK_AE_SNEAK"                 , SPA_NO_BREAK_AE_SNEAK },
{ "ADD_SPELL_SLOTS"                   , SPA_ADD_SPELL_SLOTS },
{ "ADD_BUFF_SLOTS"                    , SPA_ADD_BUFF_SLOTS },
{ "INCREASE_NEGATIVE_HP_LIMIT"        , SPA_INCREASE_NEGATIVE_HP_LIMIT },
{ "MANA_ABSORB_PCT_DMG"               , SPA_MANA_ABSORB_PCT_DMG },
{ "CRIT_ATTACK_MODIFIER"              , SPA_CRIT_ATTACK_MODIFIER },
{ "FAIL_ALCHEMY_ITEM_RECOVERY"        , SPA_FAIL_ALCHEMY_ITEM_RECOVERY },
{ "SUMMON_TO_CORPSE"                  , SPA_SUMMON_TO_CORPSE },
{ "DOOM_RUNE_EFFECT"                  , SPA_DOOM_RUNE_EFFECT },
{ "NO_MOVE_HP"                        , SPA_NO_MOVE_HP },
{ "FOCUSED_IMMUNITY"                  , SPA_FOCUSED_IMMUNITY },
{ "ILLUSIONARY_TARGET"                , SPA_ILLUSIONARY_TARGET },
{ "INCREASE_EXP_MOD"                  , SPA_INCREASE_EXP_MOD },
{ "EXPEDIENT_RECOVERY"                , SPA_EXPEDIENT_RECOVERY },
{ "FOCUS_CASTING_PROC"                , SPA_FOCUS_CASTING_PROC },
{ "CHANCE_SPELL"                      , SPA_CHANCE_SPELL },
{ "WORN_ATTACK_CAP"                   , SPA_WORN_ATTACK_CAP },
{ "NO_PANIC"                          , SPA_NO_PANIC },
{ "SPELL_INTERRUPT"                   , SPA_SPELL_INTERRUPT },
{ "ITEM_CHANNELING"                   , SPA_ITEM_CHANNELING },
{ "ASSASSINATE_MAX_LEVEL"             , SPA_ASSASSINATE_MAX_LEVEL },
{ "HEADSHOT_MAX_LEVEL"                , SPA_HEADSHOT_MAX_LEVEL },
{ "DOUBLE_RANGED_ATTACK"              , SPA_DOUBLE_RANGED_ATTACK },
{ "FOCUS_MANA_MIN"                    , SPA_FOCUS_MANA_MIN },
{ "INCREASE_SHIELD_DMG"               , SPA_INCREASE_SHIELD_DMG },
{ "MANABURN"                          , SPA_MANABURN },
{ "SPAWN_INTERACTIVE_OBJECT"          , SPA_SPAWN_INTERACTIVE_OBJECT },
{ "INCREASE_TRAP_COUNT"               , SPA_INCREASE_TRAP_COUNT },
{ "INCREASE_SOI_COUNT"                , SPA_INCREASE_SOI_COUNT },
{ "DEACTIVATE_ALL_TRAPS"              , SPA_DEACTIVATE_ALL_TRAPS },
{ "LEARN_TRAP"                        , SPA_LEARN_TRAP },
{ "CHANGE_TRIGGER_TYPE"               , SPA_CHANGE_TRIGGER_TYPE },
{ "FOCUS_MUTE"                        , SPA_FOCUS_MUTE },
{ "INSTANT_MANA"                      , SPA_INSTANT_MANA },
{ "PASSIVE_SENSE_TRAP"                , SPA_PASSIVE_SENSE_TRAP },
{ "PROC_ON_KILL_SHOT"                 , SPA_PROC_ON_KILL_SHOT },
{ "PROC_ON_DEATH"                     , SPA_PROC_ON_DEATH },
{ "POTION_BELT"                       , SPA_POTION_BELT },
{ "BANDOLIER"                         , SPA_BANDOLIER },
{ "ADD_TRIPLE_ATTACK_CHANCE"          , SPA_ADD_TRIPLE_ATTACK_CHANCE },
{ "PROC_ON_SPELL_KILL_SHOT"           , SPA_PROC_ON_SPELL_KILL_SHOT },
{ "GROUP_SHIELDING"                   , SPA_GROUP_SHIELDING },
{ "MODIFY_BODY_TYPE"                  , SPA_MODIFY_BODY_TYPE },
{ "MODIFY_FACTION"                    , SPA_MODIFY_FACTION },
{ "CORRUPTION"                        , SPA_CORRUPTION },
{ "RESIST_CORRUPTION"                 , SPA_RESIST_CORRUPTION },
{ "SLOW"                              , SPA_SLOW },
{ "GRANT_FORAGING"                    , SPA_GRANT_FORAGING },
{ "DOOM_ALWAYS"                       , SPA_DOOM_ALWAYS },
{ "TRIGGER_SPELL"                     , SPA_TRIGGER_SPELL },
{ "CRIT_DOT_DMG_MOD"                  , SPA_CRIT_DOT_DMG_MOD },
{ "FLING"                             , SPA_FLING },
{ "DOOM_ENTITY"                       , SPA_DOOM_ENTITY },
{ "RESIST_OTHER_SPA"                  , SPA_RESIST_OTHER_SPA },
{ "DIRECTIONAL_TELEPORT"              , SPA_DIRECTIONAL_TELEPORT },
{ "EXPLOSIVE_KNOCKBACK"               , SPA_EXPLOSIVE_KNOCKBACK },
{ "FLING_TOWARD"                      , SPA_FLING_TOWARD },
{ "SUPPRESSION"                       , SPA_SUPPRESSION },
{ "FOCUS_CASTING_PROC_NORMALIZED"     , SPA_FOCUS_CASTING_PROC_NORMALIZED },
{ "FLING_AT"                          , SPA_FLING_AT },
{ "FOCUS_WHICH_GROUP"                 , SPA_FOCUS_WHICH_GROUP },
{ "DOOM_DISPELLER"                    , SPA_DOOM_DISPELLER },
{ "DOOM_DISPELLEE"                    , SPA_DOOM_DISPELLEE },
{ "SUMMON_ALL_CORPSES"                , SPA_SUMMON_ALL_CORPSES },
{ "REFRESH_SPELL_TIMER"               , SPA_REFRESH_SPELL_TIMER },
{ "LOCKOUT_SPELL_TIMER"               , SPA_LOCKOUT_SPELL_TIMER },
{ "FOCUS_MANA_MAX"                    , SPA_FOCUS_MANA_MAX },
{ "FOCUS_HEAL_AMT"                    , SPA_FOCUS_HEAL_AMT },
{ "FOCUS_HEAL_MOD_BENEFICIAL"         , SPA_FOCUS_HEAL_MOD_BENEFICIAL },
{ "FOCUS_HEAL_AMT_BENEFICIAL"         , SPA_FOCUS_HEAL_AMT_BENEFICIAL },
{ "FOCUS_HEAL_MOD_CRIT"               , SPA_FOCUS_HEAL_MOD_CRIT },
{ "FOCUS_HEAL_AMT_CRIT"               , SPA_FOCUS_HEAL_AMT_CRIT },
{ "ADD_PET_AC"                        , SPA_ADD_PET_AC },
{ "FOCUS_SWARM_PET_DURATION"          , SPA_FOCUS_SWARM_PET_DURATION },
{ "FOCUS_TWINCAST_CHANCE"             , SPA_FOCUS_TWINCAST_CHANCE },
{ "HEALBURN"                          , SPA_HEALBURN },
{ "MANA_IGNITE"                       , SPA_MANA_IGNITE },
{ "ENDURANCE_IGNITE"                  , SPA_ENDURANCE_IGNITE },
{ "FOCUS_SPELL_CLASS"                 , SPA_FOCUS_SPELL_CLASS },
{ "FOCUS_SPELL_SUBCLASS"              , SPA_FOCUS_SPELL_SUBCLASS },
{ "STAFF_BLOCK_CHANCE"                , SPA_STAFF_BLOCK_CHANCE },
{ "DOOM_LIMIT_USE"                    , SPA_DOOM_LIMIT_USE },
{ "DOOM_FOCUS_USED"                   , SPA_DOOM_FOCUS_USED },
{ "LIMIT_HP"                          , SPA_LIMIT_HP },
{ "LIMIT_MANA"                        , SPA_LIMIT_MANA },
{ "LIMIT_ENDURANCE"                   , SPA_LIMIT_ENDURANCE },
{ "FOCUS_LIMIT_CLASS"                 , SPA_FOCUS_LIMIT_CLASS },
{ "FOCUS_LIMIT_RACE"                  , SPA_FOCUS_LIMIT_RACE },
{ "FOCUS_BASE_EFFECTS"                , SPA_FOCUS_BASE_EFFECTS },
{ "FOCUS_LIMIT_SKILL"                 , SPA_FOCUS_LIMIT_SKILL },
{ "FOCUS_LIMIT_ITEM_CLASS"            , SPA_FOCUS_LIMIT_ITEM_CLASS },
{ "AC2"                               , SPA_AC2 },
{ "MANA2"                             , SPA_MANA2 },
{ "FOCUS_INCREASE_SKILL_DMG_2"        , SPA_FOCUS_INCREASE_SKILL_DMG_2 },
{ "PROC_EFFECT_2"                     , SPA_PROC_EFFECT_2 },
{ "FOCUS_LIMIT_USE"                   , SPA_FOCUS_LIMIT_USE },
{ "FOCUS_LIMIT_USE_AMT"               , SPA_FOCUS_LIMIT_USE_AMT },
{ "FOCUS_LIMIT_USE_MIN"               , SPA_FOCUS_LIMIT_USE_MIN },
{ "FOCUS_LIMIT_USE_TYPE"              , SPA_FOCUS_LIMIT_USE_TYPE },
{ "GRAVITATE"                         , SPA_GRAVITATE },
{ "FLY"                               , SPA_FLY },
{ "ADD_EXTENDED_TARGET_SLOTS"         , SPA_ADD_EXTENDED_TARGET_SLOTS },
{ "SKILL_PROC"                        , SPA_SKILL_PROC },
{ "PROC_SKILL_MODIFIER"               , SPA_PROC_SKILL_MODIFIER },
{ "SKILL_PROC_SUCCESS"                , SPA_SKILL_PROC_SUCCESS },
{ "POST_EFFECT"                       , SPA_POST_EFFECT },
{ "POST_EFFECT_DATA"                  , SPA_POST_EFFECT_DATA },
{ "EXPAND_MAX_ACTIVE_TROPHY_BENEFITS" , SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS },
{ "ADD_NORMALIZED_SKILL_MIN_DMG_AMT"  , SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT },
{ "ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2", SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2 },
{ "FRAGILE_DEFENSE"                   , SPA_FRAGILE_DEFENSE },
{ "FREEZE_BUFF_TIMER"                 , SPA_FREEZE_BUFF_TIMER },
{ "TELEPORT_TO_ANCHOR"                , SPA_TELEPORT_TO_ANCHOR },
{ "TRANSLOCATE_TO_ANCHOR"             , SPA_TRANSLOCATE_TO_ANCHOR },
{ "ASSASSINATE"                       , SPA_ASSASSINATE },
{ "FINISHING_BLOW_MAX"                , SPA_FINISHING_BLOW_MAX },
{ "DISTANCE_REMOVAL"                  , SPA_DISTANCE_REMOVAL },
{ "REQUIRE_TARGET_DOOM"               , SPA_REQUIRE_TARGET_DOOM },
{ "REQUIRE_CASTER_DOOM"               , SPA_REQUIRE_CASTER_DOOM },
{ "IMPROVED_TAUNT"                    , SPA_IMPROVED_TAUNT },
{ "ADD_MERC_SLOT"                     , SPA_ADD_MERC_SLOT },
{ "STACKER_A"                         , SPA_STACKER_A },
{ "STACKER_B"                         , SPA_STACKER_B },
{ "STACKER_C"                         , SPA_STACKER_C },
{ "STACKER_D"                         , SPA_STACKER_D },
{ "DOT_GUARD"                         , SPA_DOT_GUARD },
{ "MELEE_THRESHOLD_GUARD"             , SPA_MELEE_THRESHOLD_GUARD },
{ "SPELL_THRESHOLD_GUARD"             , SPA_SPELL_THRESHOLD_GUARD },
{ "MELEE_THRESHOLD_DOOM"              , SPA_MELEE_THRESHOLD_DOOM },
{ "SPELL_THRESHOLD_DOOM"              , SPA_SPELL_THRESHOLD_DOOM },
{ "ADD_HATE_PCT"                      , SPA_ADD_HATE_PCT },
{ "ADD_HATE_OVER_TIME_PCT"            , SPA_ADD_HATE_OVER_TIME_PCT },
{ "RESOURCE_TAP"                      , SPA_RESOURCE_TAP },
{ "FACTION_MOD"                       , SPA_FACTION_MOD },
{ "SKILL_DAMAGE_MOD_2"                , SPA_SKILL_DAMAGE_MOD_2 },
{ "OVERRIDE_NOT_FOCUSABLE"            , SPA_OVERRIDE_NOT_FOCUSABLE },
{ "FOCUS_DAMAGE_MOD_2"                , SPA_FOCUS_DAMAGE_MOD_2 },
{ "FOCUS_DAMAGE_AMT_2"                , SPA_FOCUS_DAMAGE_AMT_2 },
{ "SHIELD"                            , SPA_SHIELD },
{ "PC_PET_RAMPAGE"                    , SPA_PC_PET_RAMPAGE },
{ "PC_PET_AE_RAMPAGE"                 , SPA_PC_PET_AE_RAMPAGE },
{ "PC_PET_FLURRY"                     , SPA_PC_PET_FLURRY },
{ "DAMAGE_SHIELD_MITIGATION_AMT"      , SPA_DAMAGE_SHIELD_MITIGATION_AMT },
{ "DAMAGE_SHIELD_MITIGATION_PCT"      , SPA_DAMAGE_SHIELD_MITIGATION_PCT },
{ "CHANCE_BEST_IN_SPELL_GROUP"        , SPA_CHANCE_BEST_IN_SPELL_GROUP },
{ "TRIGGER_BEST_IN_SPELL_GROUP"       , SPA_TRIGGER_BEST_IN_SPELL_GROUP },
{ "DOUBLE_MELEE_ATTACKS"              , SPA_DOUBLE_MELEE_ATTACKS },
{ "AA_BUY_NEXT_RANK"                  , SPA_AA_BUY_NEXT_RANK },
{ "DOUBLE_BACKSTAB_FRONT"             , SPA_DOUBLE_BACKSTAB_FRONT },
{ "PET_MELEE_CRIT_DMG_MOD"            , SPA_PET_MELEE_CRIT_DMG_MOD },
{ "TRIGGER_SPELL_NON_ITEM"            , SPA_TRIGGER_SPELL_NON_ITEM },
{ "WEAPON_STANCE"                     , SPA_WEAPON_STANCE },
{ "HATELIST_TO_TOP"                   , SPA_HATELIST_TO_TOP },
{ "HATELIST_TO_TAIL"                  , SPA_HATELIST_TO_TAIL },
{ "FOCUS_LIMIT_MIN_VALUE"             , SPA_FOCUS_LIMIT_MIN_VALUE },
{ "FOCUS_LIMIT_MAX_VALUE"             , SPA_FOCUS_LIMIT_MAX_VALUE },
{ "FOCUS_CAST_SPELL_ON_LAND"          , SPA_FOCUS_CAST_SPELL_ON_LAND },
{ "SKILL_BASE_DAMAGE_MOD"             , SPA_SKILL_BASE_DAMAGE_MOD },
{ "FOCUS_INCOMING_DMG_MOD"            , SPA_FOCUS_INCOMING_DMG_MOD },
{ "FOCUS_INCOMING_DMG_AMT"            , SPA_FOCUS_INCOMING_DMG_AMT },
{ "FOCUS_LIMIT_CASTER_CLASS"          , SPA_FOCUS_LIMIT_CASTER_CLASS },
{ "FOCUS_LIMIT_SAME_CASTER"           , SPA_FOCUS_LIMIT_SAME_CASTER },
{ "EXTEND_TRADESKILL_CAP"             , SPA_EXTEND_TRADESKILL_CAP },
{ "DEFENDER_MELEE_FORCE_PCT"          , SPA_DEFENDER_MELEE_FORCE_PCT },
{ "WORN_ENDURANCE_REGEN_CAP"          , SPA_WORN_ENDURANCE_REGEN_CAP },
{ "FOCUS_MIN_REUSE_TIME"              , SPA_FOCUS_MIN_REUSE_TIME },
{ "FOCUS_MAX_REUSE_TIME"              , SPA_FOCUS_MAX_REUSE_TIME },
{ "FOCUS_ENDURANCE_MIN"               , SPA_FOCUS_ENDURANCE_MIN },
{ "FOCUS_ENDURANCE_MAX"               , SPA_FOCUS_ENDURANCE_MAX },
{ "PET_ADD_ATK"                       , SPA_PET_ADD_ATK },
{ "FOCUS_DURATION_MAX"                , SPA_FOCUS_DURATION_MAX },
{ "CRIT_MELEE_DMG_MOD_MAX"            , SPA_CRIT_MELEE_DMG_MOD_MAX },
{ "FOCUS_CAST_PROC_NO_BYPASS"         , SPA_FOCUS_CAST_PROC_NO_BYPASS },
{ "ADD_EXTRA_PRIMARY_ATTACK_PCT"      , SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT },
{ "ADD_EXTRA_SECONDARY_ATTACK_PCT"    , SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT },
{ "FOCUS_CAST_TIME_MOD2"              , SPA_FOCUS_CAST_TIME_MOD2 },
{ "FOCUS_CAST_TIME_AMT"               , SPA_FOCUS_CAST_TIME_AMT },
{ "FEARSTUN"                          , SPA_FEARSTUN },
{ "MELEE_DMG_POSITION_MOD"            , SPA_MELEE_DMG_POSITION_MOD },
{ "MELEE_DMG_POSITION_AMT"            , SPA_MELEE_DMG_POSITION_AMT },
{ "DMG_TAKEN_POSITION_MOD"            , SPA_DMG_TAKEN_POSITION_MOD },
{ "DMG_TAKEN_POSITION_AMT"            , SPA_DMG_TAKEN_POSITION_AMT },
{ "AMPLIFY_MOD"                       , SPA_AMPLIFY_MOD },
{ "AMPLIFY_AMT"                       , SPA_AMPLIFY_AMT },
{ "HEALTH_TRANSFER"                   , SPA_HEALTH_TRANSFER },
{ "FOCUS_RESIST_INCOMING"             , SPA_FOCUS_RESIST_INCOMING },
{ "FOCUS_TIMER_MIN"                   , SPA_FOCUS_TIMER_MIN },
{ "PROC_TIMER_MOD"                    , SPA_PROC_TIMER_MOD },
{ "MANA_MAX"                          , SPA_MANA_MAX },
{ "ENDURANCE_MAX"                     , SPA_ENDURANCE_MAX },
{ "AC_AVOIDANCE_MAX"                  , SPA_AC_AVOIDANCE_MAX },
{ "AC_MITIGATION_MAX"                 , SPA_AC_MITIGATION_MAX },
{ "ATTACK_OFFENSE_MAX"                , SPA_ATTACK_OFFENSE_MAX },
{ "ATTACK_ACCURACY_MAX"               , SPA_ATTACK_ACCURACY_MAX },
{ "LUCK_AMT"                          , SPA_LUCK_AMT },
{ "LUCK_PCT"                          , SPA_LUCK_PCT },
{ "ENDURANCE_ABSORB_PCT_DMG"          , SPA_ENDURANCE_ABSORB_PCT_DMG },
{ "INSTANT_MANA_PCT"                  , SPA_INSTANT_MANA_PCT },
{ "INSTANT_ENDURANCE_PCT"             , SPA_INSTANT_ENDURANCE_PCT },
{ "DURATION_HP_PCT"                   , SPA_DURATION_HP_PCT },
{ "DURATION_MANA_PCT"                 , SPA_DURATION_MANA_PCT },
{ "DURATION_ENDURANCE_PCT"            , SPA_DURATION_ENDURANCE_PCT },
}
*/