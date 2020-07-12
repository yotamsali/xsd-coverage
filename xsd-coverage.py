class XMLsPoolParser:
    def __init__(self, root_path):
        self._root_path = root_path
        self._xml_paths = self.get_all_xmls_paths(root_path)

    @classmethod
    def get_all_xmls_paths(cls, root_path):
        return

    @staticmethod
    def _get_all_xml_chains(xml_file_path):
        with open(xml_file_path, 'wb') as xml_file:
            xml_content = xml_file.read()

    def has_element(self, element):
        return False


def test_xsd_coverage():
    xmls_parser = XMLsPoolParser()


if __name__ == '__main__':
    test_xsd_coverage()