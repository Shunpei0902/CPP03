/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:27:10 by sasano            #+#    #+#             */
/*   Updated: 2025/01/19 02:41:24 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    // コンストラクタのテスト
    std::cout << "=== Constructing FragTrap instances ===" << std::endl;
    FragTrap flaptrap("Flaptrap");
    FragTrap flaptrap2("Flaptrap2");
    FragTrap flaptrap3(flaptrap); // コピーコンストラクタ
    FragTrap flaptrap4 = flaptrap2; // 代入演算子

    // メンバ関数の動作確認
    std::cout << "=== Testing basic operations ===" << std::endl;
    flaptrap.attack("enemy");
    flaptrap.takeDamage(5);
    flaptrap.beRepaired(3);

    std::cout << "=== Testing high fives ===" << std::endl;
    flaptrap.highFivesGuys();

    // 異常系やエッジケースの確認
    std::cout << "=== Edge case testing ===" << std::endl;

    // 大量のダメージを受ける
    flaptrap.takeDamage(9999); // オーバーフローや異常動作の確認
    flaptrap.beRepaired(100); // 修理可能かどうか確認

    // 残りHPが0での動作
    flaptrap2.takeDamage(100); // HPが尽きる
    flaptrap2.attack("enemy"); // HPが0で攻撃可能か確認
    flaptrap2.highFivesGuys(); // HPが0での特別な操作

    // コピーされたオブジェクトの独立性確認
    std::cout << "=== Verifying copy constructors ===" << std::endl;
    flaptrap3.attack("enemy from copied Claptrap");
    flaptrap4.highFivesGuys();

    std::cout << "=== All tests completed ===" << std::endl;
    return (0);
}


