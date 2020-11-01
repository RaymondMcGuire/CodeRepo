/*** 
 * @Author: Xu.WANG
 * @Date: 2020-11-02 02:59:10
 * @LastEditTime: 2020-11-02 03:02:20
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\fbs\fbs_sample.h
 */
#pragma once
#include <kiri_func.h>
#include <fbs/monster_generated.h>
using namespace MyGame::Sample;

void fbs_write_sample()
{
    flatbuffers::FlatBufferBuilder builder(1024);
    auto weapon_one_name = builder.CreateString("Sword");
    short weapon_one_damage = 3;
    auto weapon_two_name = builder.CreateString("Axe");
    short weapon_two_damage = 5;
    // Use the `CreateWeapon` shortcut to create Weapons with all the fields set.
    auto sword = CreateWeapon(builder, weapon_one_name, weapon_one_damage);
    auto axe = CreateWeapon(builder, weapon_two_name, weapon_two_damage);
    // Serialize a name for our monster, called "Orc".
    auto name = builder.CreateString("Orc");
    // Create a `vector` representing the inventory of the Orc. Each number
    // could correspond to an item that can be claimed after he is slain.
    unsigned char treasure[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto inventory = builder.CreateVector(treasure, 10);
    // Place the weapons into a `std::vector`, then convert that into a FlatBuffer `vector`.
    std::vector<flatbuffers::Offset<Weapon>> weapons_vector;
    weapons_vector.push_back(sword);
    weapons_vector.push_back(axe);
    auto weapons = builder.CreateVector(weapons_vector);
    Vec3 points[] = {Vec3(1.0f, 2.0f, 3.0f), Vec3(4.0f, 5.0f, 6.0f)};
    auto path = builder.CreateVectorOfStructs(points, 2);
    // Create the position struct
    auto position = Vec3(1.0f, 2.0f, 3.0f);
    // Set his hit points to 300 and his mana to 150.
    int hp = 300;
    int mana = 150;
    // Finally, create the monster using the `CreateMonster` helper function
    // to set all fields.
    auto orc = CreateMonster(builder, &position, mana, hp, name, inventory,
                             Color_Red, weapons, Equipment_Weapon, axe.Union(),
                             path);
    builder.Finish(orc);
    uint8_t *buf = builder.GetBufferPointer();
    int size = builder.GetSize();

    write_binary_file(buf, size);
}

void fbs_read_sample()
{
    std::string file_name = "data.bin";
    std::vector<char> data = read_binary_file(file_name);
    auto monster = GetMonster(data.data());
    auto hp = monster->hp();
    auto mana = monster->mana();
    auto name = monster->name()->c_str();
    KIRI_LOG_DEBUG("Read Data From File:{0}", file_name);
    KIRI_LOG_DEBUG("Monster HP={0}, mana={1}, name={2}", hp, mana, name);

    auto pos = monster->pos();
    auto x = pos->x();
    auto y = pos->y();
    auto z = pos->z();
    KIRI_LOG_DEBUG("Monster Position=({0},{1},{2})", x, y, z);
    auto inv = monster->inventory(); // A pointer to a `flatbuffers::Vector<>`.
    auto inv_len = inv->size();
    auto third_item = inv->Get(2);
    KIRI_LOG_DEBUG("Monster Inventory Size={0}", inv_len);
    KIRI_LOG_DEBUG("Third Item={0}", third_item);
    auto weapons = monster->weapons(); // A pointer to a `flatbuffers::Vector<>`.
    auto weapon_len = weapons->size();
    auto second_weapon_name = weapons->Get(1)->name()->str();
    auto second_weapon_damage = weapons->Get(1)->damage();
    KIRI_LOG_DEBUG("Monster Weapon Size={0}", weapon_len);
    KIRI_LOG_DEBUG("Second Weapon Name={0}, Damage={1}", second_weapon_name, second_weapon_damage);
    auto union_type = monster->equipped_type();
    if (union_type == Equipment_Weapon)
    {
        auto weapon = static_cast<const Weapon *>(monster->equipped()); // Requires `static_cast`
                                                                        // to type `const Weapon*`.
        auto weapon_name = weapon->name()->str();                       // "Axe"
        auto weapon_damage = weapon->damage();                          // 5
        KIRI_LOG_DEBUG("Monster Current Equipped Weapon={0},Damage={1}", weapon_name, weapon_damage);
    }
}