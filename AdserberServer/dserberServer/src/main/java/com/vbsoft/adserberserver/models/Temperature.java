package com.vbsoft.adserberserver.models;


import com.vaadin.flow.component.Component;
import com.vaadin.flow.component.Tag;
import com.vaadin.flow.component.html.Label;

@Tag("temperature")
public class Temperature extends Component {


    public Temperature(String name, String temperature) {
        this.name = name;
        this.temperature = temperature;
        this.getElement().setAttribute("title", name).setAttribute("current", temperature);

    }

    String name;

    String temperature;

}
