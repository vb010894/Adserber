package com.vbsoft.adserberserver.models;

import com.vaadin.flow.component.tabs.Tab;
import lombok.AccessLevel;
import lombok.Builder;
import lombok.Getter;
import lombok.experimental.FieldDefaults;

@Builder(access = AccessLevel.PUBLIC, builderClassName = "Builder")
@Getter
@FieldDefaults(level = AccessLevel.PRIVATE)
public class TabModel {

    public static class Builder {

        public Builder() {

        }

    }

    String ID;

    Tab tab;

    String route;

    public boolean isSelectedTab(String id) {
        return this.ID.equals(id);
    }

}
