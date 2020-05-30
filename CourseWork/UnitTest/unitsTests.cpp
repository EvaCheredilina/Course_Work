#include "pch.h"
#include "CppUnitTest.h"
#include"..//CourseWork/FlowCounterRepresenter.h"
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFlowPushRelabel
{
	TEST_CLASS(UnitTestFlowPushRelabel)
	{
	public:

		TEST_METHOD(TestMethod_Ñorrect_output_for_6_vertexes)
		{
			ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input1.txt");
			FlowCounterRepresenter flow(input);
			Assert::AreEqual(flow.countMaxFlow(), 5);
		}
		TEST_METHOD(TestMethod_Exception_entering_the_first_character) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input2.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(),"Error occuried while reading line 3");
			}
		}
		TEST_METHOD(TestMethod_Exception_entering_the_second_character) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input3.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error occuried while reading line 3");
			}
		}
		TEST_METHOD(TestMethod_Exception_entering_the_third_number_flow) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input4.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error occuried while reading line 3");
			}
		}
		TEST_METHOD(TestMethod_Exception_empty_string) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input5.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error occuried while reading line 3");
			}
		}
		TEST_METHOD(TestMethod_Ñorrect_output_for_6_vertexes_and_edge_from_source_to_sink)
		{
			ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input6.txt");
			FlowCounterRepresenter flow(input);
			Assert::AreEqual(flow.countMaxFlow(), 25);
		}
		TEST_METHOD(TestMethod_Ñorrect_output_for_2_vertexes_edges_from_source_to_sink)
		{
			ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input7.txt");
			FlowCounterRepresenter flow(input);
			Assert::AreEqual(flow.countMaxFlow(), 20);
		}
		TEST_METHOD(TestMethod_Exception_there_is_a_path_from_the_vertex_to_itself) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input8.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error occuried while reading line 3");
			}
		}
		TEST_METHOD(TestMethod_Ñorrect_output_for_20_vertexes)
		{
			ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input9.txt");
			FlowCounterRepresenter flow(input);
			Assert::AreEqual(flow.countMaxFlow(), 19);
		}
		TEST_METHOD(TestMethod_Exception_entering_the_third_negative_number_flow) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input10.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Error occuried while reading line 3");
			}
		}
		TEST_METHOD(TestMethod_Exception_sink_is_missing) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input11.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "No sink vertex");
			}
		}
		TEST_METHOD(TestMethod_Exception_source_is_missing) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input12.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "No source vertex");
			}
		}
		TEST_METHOD(TestMethod_Exception_two_different_connectivity_components) {
			try {
				ifstream input("C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\CourseWork\\CourseWork\\UnitTest\\Input13.txt");
				FlowCounterRepresenter flow(input);
			}
			catch (exception & ex) {
				Assert::AreEqual(ex.what(), "Can't reach sink vertex form source.");
			}
		}
	};
}
