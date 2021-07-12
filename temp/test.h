#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<memory>

std::map<std::string, std::string> build_map(std::ifstream & map_file)
{
	std::map<std::string, std::string> trans_map;
	std::string key, value;
	while (map_file >> key && std::getline(map_file, value))
	{
		if (value.size() > 1)
		{
			trans_map[key] = value.substr(1);
		}		
		else
		{
			throw std::runtime_error("no rule for " + key);
		}
	}
	return trans_map;
}

const std::string & transform(const std::string &s, const std::map<std::string,std::string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
	return s;
}

void word_transform(std::ifstream & map_file, std::ifstream &input_file)
{
	auto trans_map = build_map(map_file);
	std::string text;
	while (std::getline(input_file, text))
	{
		std::istringstream stream(text);
		std::string word;
		bool fist_word = true;
		while (stream >> word)
		{
			if (fist_word)
			{
				fist_word = false;
			}
			else
			{
				std::cout << " ";
			}
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

void container_test()
{
	std::string dict_name = "dict.txt", text_name = "text.txt";
	std::ifstream dict(dict_name, std::ios::in);
	if (!dict.is_open())
	{
		std::cout << dict_name << " can not open!" << std::flush;
		return;
	}
	std::ifstream text("text.txt", std::ios::in);
	if (!text.is_open())
	{
		std::cout << text_name << " can not open!" << std::flush;
		return;
	}
	word_transform(dict, text);
}

void allocator_test()
{
	int N = 2;
	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(N);
	auto q = p;
	alloc.construct(q, N, 'n');
	std::cout << "p:" << *p << "\nq:" << *q << "\n";
	while (q = p)
		alloc.destroy(q);
	alloc.deallocate(p, N);

}