# *MINIRT* 
Read the File:

~>Create a function to read the scene description file. This function should take the file path as input and return the contents of the file as a string or a list of lines.
Open the file using the open system call and check for any errors using perror and exit if necessary.
Read the file contents using the read system call or similar file reading functions.
Close the file using the close system call.
Split Elements:

~>Create a function to split the contents of the file into separate elements. Each element represents a different object or setting in the scene.
Split the file contents by line breaks (n) to separate each element.
You can store the split elements in a list or any other suitable data structure for further processing.
Process Elements:

~>Iterate through each element and process them accordingly based on their type.
Implement separate functions for each type of element (ambient lighting, camera, light, sphere, plane, cylinder) to handle their specific parsing and processing logic.
Process Ambient Lighting:

~>Create a function to parse and process the ambient lighting element.
Extract the ambient lighting ratio and RGB color values from the element.
Convert and store the values in suitable data structures or variables for later use.
Process Camera:

~>Create a function to parse and process the camera element.
Extract the view point coordinates, normalized orientation vector, and field of view (FOV) from the element.
Convert and store the values in suitable data structures or variables for later use.
Process Light:

~>Create a function to parse and process the light element.
Extract the light point coordinates, brightness ratio, and RGB color values from the element.
Convert and store the values in suitable data structures or variables for later use.
Process Sphere:

~>Create a function to parse and process the sphere element.
Extract the sphere center coordinates, diameter, and RGB color values from the element.
Convert and store the values in suitable data structures or variables for later use.
Process Plane:

Create a function to parse and process the plane element.
Extract the plane point coordinates, normalized normal vector, and RGB color values from the element.
Convert and store the values in suitable data structures or variables for later use.
Process Cylinder:

Create a function to parse and process the cylinder element.
Extract the cylinder center coordinates, normalized axis vector, diameter, height, and RGB color values from the element.
Convert and store the values in suitable data structures or variables for later use.
These functions will help you parse and process the different elements in the scene description file. You can further enhance these functions based on your specific implementation requirements and error handling needs. Remember to handle any potential errors that may occur during parsing, such as invalid input formats or missing information.

By implementing these functions, you will be able to extract and store the necessary information from the scene description file to create your raytracer program.
