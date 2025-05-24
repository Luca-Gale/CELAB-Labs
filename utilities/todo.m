function todo(lab_number)

if nargin < 1
    uialert(uifigure, 'Please provide the lab number: e.g., "1", "2", ...', 'Missing Input');
    return;
end

% Construct the filename based on input
filename = "lab" + lab_number + "_todo_list.csv";

% Store current warning state
ws = warning;

% Turn off all warnings (or specific ones)
warning('off', 'all');

% Try to load the corresponding CSV file
try
    todo = readtable(filename);
catch
    uialert(uifigure, "Checklist file not found: " + filename, "Error");
    warning(ws); % Restore warnings before exiting
    return;
end

% Create UI figure
f = uifigure('Name', "Lab " + lab_number + " To-Do List", 'Position', [100 100 900 450]);


% Create the interactive table
uit = uitable(f, ...
    'Data', todo, ...
    'ColumnEditable', [true true true true], ...
    'ColumnName', todo.Properties.VariableNames, ...
    'Position', [10 60 880 370]);

% Create Save button
uibutton(f, ...
    'Text', '💾 Save Progress', ...
    'Position', [10 10 120 30], ...
    'ButtonPushedFcn', @(btn, event) saveTable(uit, f));

% Callback function nested inside main GUI function
    function saveTable(uit, f)
        % Save the data from the table to the correct file
        writetable(uit.Data, filename);
        uialert(f, "Progress saved!", "Success");
    end

% Restore original warning state
warning(ws);

end
