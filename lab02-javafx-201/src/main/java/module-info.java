module ku.cs.lab02javafx201 {
    requires javafx.controls;
    requires javafx.fxml;


    opens ku.cs.lab02javafx201 to javafx.fxml;
    exports ku.cs.lab02javafx201;
    exports ku.cs.controllers;
    opens ku.cs.controllers to javafx.fxml;
}