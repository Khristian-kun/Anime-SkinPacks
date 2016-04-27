#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <substrate.h>
#include <memory>
#include <string>
#include <vector>
#include "dl_internal.h"
#include "tinyhook.h"
#include "shared.h"


#include "mcpe/client/resources/Skin.h"
#include "mcpe/client/resources/SkinPack.h"
#include "mcpe/client/resources/SkinRepository.h"

#include "mcpe/client/settings/Options.h"

class GameStore;
class Textures;
class GeometryGroup;
class TextureGroup;

void (*skinRepoOrg)(SkinRepository*, Options&, GeometryGroup&, GameStore&, TextureGroup&, std::string const&, unsigned long long);
void skinRepoHook(SkinRepository* repo, Options& op, GeometryGroup& ge, GameStore& st, TextureGroup& tex, std::string const& text, unsigned long long HELP) {
skinRepoOrg(repo, op, ge, st, tex, text, HELP);

//SAO
Skin KiritoCM("Kirito: Coat of Midnight", "Kirito: Coat of midnight", "geometry.humanoid.normal", "mob/skins/SAO/Kirito.png", Skin::SkinType::FREE);

Skin KiritoKB("Kirito: Knights of the Blood", "Kirito: Knights of the Blood", "geometry.humanoid.normal", "mob/skins/SAO/Kirito2.png", Skin::SkinType::FREE);

Skin KiritoAlt("Kirito: Alternative", "Kirito: Alternative", "geometry.humanoid.slim", "mob/skins/SAO/Kirito3.png", Skin::SkinType::FREE);

Skin Klein("Klein", "Klein", "geometry.humanoid.normal", "mob/skins/SAO/Klein.png", Skin::SkinType::FREE);

Skin Agil("Agil the Merchant", "Agil the Merchant", "geometry.humanoid.normal", "mob/skins/SAO/Agil.png", Skin::SkinType::FREE);

Skin Asuna("Asuna the FlashLight", "Asuna the FlashLight", "geometry.humanoid.slim", "mob/skins/SAO/Asuna.png", Skin::SkinType::FREE);

Skin Lizbeth("Lizbeth the Blacksmith", "Lizbeth the Blacksmith", "geometry.humanoid.slim", "mob/skins/SAO/Lizbeth.png", Skin::SkinType::FREE);

Skin Silica("Silica the Dragon Tamer", "Silica the Dragon Tamer", "geometry.humanoid.slim", "mob/skins/SAO/Silica.png", Skin::SkinType::FREE);

Skin Strea("Strea-MHCP002", "Strea-MHCP002", "geometry.humanoid.normal", "mob/skins/SAO/Strea.png", Skin::SkinType::FREE);

Skin Philia("Philia the Treasure Hunter", "Philia the Treasure Hunter", "geometry.humanoid.slim", "mob/skins/SAO/Philia.png", Skin::SkinType::FREE);

SkinPack * SAOSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "Sword Art Online: World of Aincrad", "SAO: WoA", true, {
    KiritoCM,
    KiritoKB,
    KiritoAlt,
    Klein,
    Agil,
    Asuna,
    Lizbeth,
    Silica,
    Strea,
    Philia
});
repo->skinPacks.push_back(SAOSkinPack);
SAOSkinPack->unlocked = true;

//ALO
Skin KiritoALO("Kirito", "Kirito", "geometry.humanoid.normalwings", "mob/skins/ALO/Kirito.png", Skin::SkinType::FREE);

Skin KiritoFD("Kirito: Fairy Dance", "Kirito: Fairy Dance", "geometry.humanoid.normalwings", "mob/skins/ALO/KiritoFairyDance.png", Skin::SkinType::FREE);

Skin LeafaALO("Leafa", "Leafa", "geometry.humanoid.normalwings", "mob/skins/ALO/Leafa.png", Skin::SkinType::FREE);

Skin AsunaALO("Asuna", "Asuna", "geometry.humanoid.normalwings", "mob/skins/ALO/Asuna.png", Skin::SkinType::FREE);

Skin LizbethALO("Lizbeth", "Lizbeth", "geometry.humanoid.normalwings", "mob/skins/ALO/Lizbeth.png", Skin::SkinType::FREE);

Skin SilicaALO("Silica", "Silica", "geometry.humanoid.normalwings", "mob/skins/ALO/Silica.png", Skin::SkinType::FREE);

Skin SinonALO("Sinon", "Sinon", "geometry.humanoid.normalwings", "mob/skins/ALO/Sinon.png", Skin::SkinType::FREE);

Skin YuukiALO("Yuuki", "Yuuki", "geometry.humanoid.normalwings", "mob/skins/ALO/Yuuki.png", Skin::SkinType::FREE);

SkinPack * ALOSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "Sword Art Online: ALfheim Online", "SAO: ALO", true, {
    KiritoALO,
    KiritoFD,
    LeafaALO,
    AsunaALO,
    LizbethALO,
    SilicaALO,
    SinonALO,
    YuukiALO
});
repo->skinPacks.push_back(ALOSkinPack);
ALOSkinPack->unlocked = true;

//GGO
Skin KiritoGGO("Kirito GGO", "Kirito", "geometry.humanoid.slim", "mob/skins/GGO/Kirito.png", Skin::SkinType::FREE);

Skin SinonGGO("Sinon GGO", "Sinon", "geometry.humanoid.slim", "mob/skins/GGO/Sinon.png", Skin::SkinType::FREE);

Skin DeathGun("DeathGun", "DeathGun", "geometry.humanoid.normal", "mob/skins/GGO/DeathGun.png", Skin::SkinType::FREE);

SkinPack * GGOSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "Sword Art Online: Gun Gale Online", "SAO: GGO", true, {
    KiritoGGO,
    SinonGGO,
    DeathGun
});
repo->skinPacks.push_back(GGOSkinPack);
GGOSkinPack->unlocked = true;

//Shingeki No Kyojin SkinPack
Skin Eren("Eren", "Eren", "geometry.humanoid.normalgear", "mob/skins/SNK/Eren.png", Skin::SkinType::FREE);

Skin Levi("Levi", "Levi", "geometry.humanoid.normalgear", "mob/skins/SNK/Levi.png", Skin::SkinType::FREE);

Skin Mikasa("Mikasa", "Mikasa", "geometry.humanoid.normalgear", "mob/skins/SNK/Mikasa.png", Skin::SkinType::FREE);

SkinPack * SNKSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "Shingeki No Kyoji", "Shingeki No Kyojin", true, {
    Eren,
    Levi,
    Mikasa
});
repo->skinPacks.push_back(SNKSkinPack);
SNKSkinPack->unlocked = true;

//Mirai Nikki
Skin YunoGasai("Yuno Gasai", "Yuno Gasai", "geometry.humanoid.normal", "mob/skins/MiraiNikki/YunoGasai.png", Skin::SkinType::FREE);
Skin Yuki("Yuki", "Yuki", "geometry.humanoid.normal", "mob/skins/MiraiNikki/Yuki.png", Skin::SkinType::FREE);
Skin Twelfth("Twelfth", "Twelfth", "geometry.humanoid.normal", "mob/skins/MiraiNikki/Twelfth.png", Skin::SkinType::FREE);

SkinPack * MiraiNikkiSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "Mirai Nikki", "Mirai Nikki", true, {
    YunoGasai,
    Yuki,
    Twelfth
});
repo->skinPacks.push_back(MiraiNikkiSkinPack);
MiraiNikkiSkinPack->unlocked = true;

//No Game No Life
Skin Sora("Sora", "Sora", "geometry.humanoid.normal", "mob/skins/NGNL/Sora.png", Skin::SkinType::FREE);
Skin Siro("Siro", "Siro", "geometry.humanoid.normal", "mob/skins/NGNL/Siro.png", Skin::SkinType::FREE);
Skin StephanieDolan("Stephanie Dolan", "Stephanie Dolan", "geometry.humanoid.normal", "mob/skins/NGNL/StephanieDolan.png", Skin::SkinType::FREE);
Skin Jibril("Jibril", "Jibril", "geometry.humanoid.normal", "mob/skins/NGNL/Jibril.png", Skin::SkinType::FREE);

SkinPack * NGNLSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "No Game No Life", "No Game No Life", true, {
    Sora,
    Siro,
    StephanieDolan,
    Jibril
});
repo->skinPacks.push_back(NGNLSkinPack);
NGNLSkinPack->unlocked = true;

//Death Note
Skin Kira("Kira", "Light - Kira", "geometry.humanoid.normal", "mob/skins/DeathNote/Light.png", Skin::SkinType::FREE);
Skin L("L", "Ryuzaki - L", "geometry.humanoid.normal", "mob/skins/DeathNote/Ryuzaki.png", Skin::SkinType::FREE);
Skin MisaAmane("Kira2", "Misa Amane - 2nd Kira", "geometry.humanoid.normal", "mob/skins/DeathNote/MisaAmane.png", Skin::SkinType::FREE);
Skin Ryuk("Ryuk", "Ryuk the Shimigami", "geometry.humanoid.normal", "mob/skins/DeathNote/Ryuk.png", Skin::SkinType::FREE);
Skin Near("Near", "Near", "geometry.humanoid.normal", "mob/skins/DeathNote/Near.png", Skin::SkinType::FREE);

SkinPack * DeathNoteSkinPack = new SkinPack(SkinPack::SkinPackType::PACK, "Death Note", "Death Note", true, {
    Kira,
    L,
    MisaAmane,
    Ryuk,
    Near
});
repo->skinPacks.push_back(DeathNoteSkinPack);
DeathNoteSkinPack->unlocked = true;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    soinfo2 *handle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);

    void *sym = dlsym(handle, "_ZN14SkinRepositoryC2ER7OptionsR13GeometryGroupR9GameStoreR12TextureGroupRKSsy");
	MSHookFunction(sym, (void *) &skinRepoHook, (void **) &skinRepoOrg);
	
	return JNI_VERSION_1_2;
}
